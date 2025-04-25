#include <iostream>
#include <cmath>
#include "Arm.h"
#include "../mob/Mob.h"

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
	 * Updates the object's logic.
	 * @param deltaTime - The time elapsed since the last frame (in ms)
	 */
	void Arm::update(float deltaTime) {

		// Get rawPos
		sf::Vector2f rawPos = getRawPos();

		// Get closest Mob to the arm
		Mob::Mob* mob = Mob::getClosestTo(rawPos);

		// If there is no mob just return
		if (mob == nullptr) return;

		// Compute position diff
		float dx = mob->pos.x - rawPos.x;
		float dy = mob->pos.y - rawPos.y;

		// Calculate angle in degrees
		float angle = std::atan2(dy, dx) * 180.f / M_PI;

		// Apply rotation to the arm's shape
		shape.setRotation(sf::degrees(angle));


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
