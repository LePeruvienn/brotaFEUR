#include "Projectile.h"
#include "../core/Game.h"
#include "../entities/mob/Mob.h"
#include "../core/rigidShapes/CircleRigidShape.h"
#include <iostream>

namespace Projectile {

	Projectile* create (
		float x, float y,
		float dx, float dy,
		float speed, float maxDuration,
		float radius, sf::Color color
	) {
		// Creating new projectile object
		Projectile* projectile = new Projectile(x, y, dx, dy, speed, maxDuration, radius, color);

		// Add projectile to the game logic
		Game::add(projectile);

		// Return pointer
		return projectile;
	}

	/**
	 * Projectile constructor
	 * @param x - x axis position
	 * @param y - y axis position
	 * @param dx - direction x where the projectile is going
	 * @param dy - direction y where the projectile is going
	 * @param speed - projectile speed
	 * @param maxDuration - time eleapsed before the projectile get deleted
	 * @param radius - projectile body radius
	 * @param color - projectile body color
	 */
	Projectile::Projectile(
		float x, float y,
		float dx, float dy,
		float speed, float maxDuration,
		float radius, sf::Color color
	// Using parent's constructor
	) : Game::Object(x, y), shape(radius), speed(speed), maxDuration(maxDuration) {
	
		direction.x = dx;
		direction.y = dy;

		// Set shape position & color
		shape.setPosition({x, y});
		shape.setFillColor(color);

		// Create entity rigidShape
		rigidShape = new Physics::CircleRigidShape (x, y, 1.f, radius);

		// Set current object as rigidShape parent's
		rigidShape->setParent(this);

		// Add the rigidShape to the Physics
		Physics::addObject (rigidShape);
	}

	/**
	 * Updates the object's logic.
	 * @param deltaTime - The time elapsed since the last frame (in ms)
	 */
	void Projectile::update(float deltaTime) {

		// Handel Projectile collisions
		handleCollisions();

		// If we have reached the max Duration delte current object
		if (elapsedTime >= maxDuration) {

			// Destroy current object
			destroy();
			
			// Stop here
			return;
		}

		// If we have not, continue move our projectile
		rigidShape->velocity.x = direction.x * speed;
		rigidShape->velocity.y = direction.y * speed;

		// Increment time eleapsed
		elapsedTime += deltaTime;
	}

	/**
	 * Callback function called before the entity is deleted
	 */
	void Projectile::onDestroy() {

		// std::cout << "Projectile : onDestroy()" << std::endl;

		// Use parent's function
		Object::onDestroy();
	}

	/**
	 * Renders the object to the specified window.
	 * @param window - Instance of the game window
	 */
	void Projectile::render(sf::RenderWindow& window) {

		// Set shape to projectile rigidShape current position
		shape.setPosition(rigidShape->pos);

		// Draw shape into the screen
		window.draw(shape);
	}

	/**
	 * Handle current projectiles collisions
	 */
	void Projectile::handleCollisions() {

		// If an entity is currently touching a the bonus
		for (auto& rs : rigidShape->collisions) {
			
			// If rs parent is null go to next collisions
			if (rs->parent == nullptr) continue;

			// Cast object as an Mob
			// ⚠️ MUST USE dynamic_cast() otherwise it will not check if the current object is of the right type !!!
			Mob::Mob* mob = dynamic_cast<Mob::Mob*>(rs->parent);

			// If cast dosnt work go to next collisions
			if (mob == nullptr) continue;

			// Apply damage to mob
			mob->stats.takeDamage(10);

			// Destroy current object
			destroy();

			break;
		}
	}
}
