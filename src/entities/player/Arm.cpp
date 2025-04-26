#include <iostream>
#include <cmath>
#include "Arm.h"
#include "../../utils/Utils.h"
#include "../../objects/Projectile.h"

namespace Player {

	/**
	 * Arm class constructor
	 * @param x - start X coordinates
	 * @param y - start Y coordinates
	 * @param size - Arm size
	 */
	Arm::Arm(float x, float y, float size)
	: Game::Object(x, y), size(size) {

		// Create Arm RectangleShape
		shape = sf::RectangleShape({size, size});

		// Set rendering origin to center
		shape.setOrigin({size / 2, size / 2});
	}

	/**
	 * Make the arm rotate towards the mob in parameter
	 * @param Mob* - mob target we want to rotate to
	 */
	void Arm::rotateTowardsMob(float deltaTime, Mob::Mob* mob) {

		// Get rawPos
		sf::Vector2f rawPos = getRawPos();

		// Compute position diff
		float dx = mob->pos.x - rawPos.x;
		float dy = mob->pos.y - rawPos.y;

		// Calculate angle in radians
		float targetAngle = std::atan2(dy, dx);
		float currentAngle = shape.getRotation().asRadians();

		// Calculate shortest angular difference
		float diff = targetAngle - currentAngle;

		// Wrap the angle between -π and π
		while (diff < -M_PI) diff += 2.f * M_PI;
		while (diff >  M_PI) diff -= 2.f * M_PI;

		// Make the transition between the 2 angles, taking part the rotation speed
		float rotation = currentAngle + diff * (rotationSpeed * deltaTime);

		// Apply rotation to the arm's shape
		shape.setRotation(sf::radians(rotation));
	}

	/**
	 * Make the arm shoot a target mob
	 * @param deltaTime - The time elapsed since the last frame (in ms)
	 * @param Mob* - mob target we want to rotate to
	 */
	void Arm::handleShoot(float deltaTime, Mob::Mob* mob) {

		// If the shotTimer has reached his end
		if (shotTimer >= shootCoolown) {

			// Get rawPos
			sf::Vector2f rawPos = getRawPos();

			// Compute direction
			float angle = shape.getRotation().asRadians();
			float dx = std::cos(angle);
			float dy = std::sin(angle);

			// Shoot a projectile toward this direction
			Projectile::create(rawPos.x, rawPos.y, dx, dy);

			// Reset shotTimer
			shotTimer = 0.f;
		}

		// Increment shotTimer
		shotTimer += deltaTime;
	}

	/**
	 * Updates the object's logic.
	 * @param deltaTime - The time elapsed since the last frame (in ms)
	 */
	void Arm::update(float deltaTime) {

		// Get rawPos, used to get in game pos, even if we are a children
		sf::Vector2f rawPos = getRawPos();

		// Get closest Mob to the arm
		Mob::Mob* mob = Mob::getClosestTo(rawPos);

		// If there is no mob just return
		if (mob == nullptr) return;

		// Rotate towards mob
		rotateTowardsMob (deltaTime, mob);

		// Shoot mob
		handleShoot (deltaTime, mob);

		// Use parent's update function !
		Game::Object::update(deltaTime);
	}

	/**
	 * Callback function called before the entity is deleted
	 */
	void Arm::onDestroy() {

		// Use parent's function
		Game::Object::onDestroy();
	}

	/**
	 * Renders the object to the specified window.
	 * @param window - Instance of the game window
	 */
	void Arm::render(sf::RenderWindow& window) {

		// User parent's render function
		Game::Object::render(window);

		// Get current pos
		float x = pos.x;
		float y = pos.y;

		// If we have a parent we must adjust the position toward parent's pos
		if (parent != nullptr) {
		
			x += parent->pos.x;
			y += parent->pos.y;
		}

		// Set shape to bonus rigidShape current position
		shape.setPosition({x, y});

		// Draw first background and then gauge to keep it in front of the background
		window.draw(shape);
	}
}
