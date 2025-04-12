#include "Entity.h"
#include "../core/Physics.h"

namespace Entity {

	/**
	 * constructs a new entity object with specified parameters.
	 * @param x - x axis position
	 * @param y - y axis position
	 * @param radius - entity body radius
	 * @param color - entity body color
	 */
	Entity::Entity(float x, float y, float radius, sf::Color color, Stats stats)
		// Intialize class values
		: shape(radius), stats(stats) {

		// Set shape position & color
		shape.setPosition({x, y});
		shape.setFillColor(color);

		// Create entity rigidShape
		rigidShape = new Physics::CircleRigidShape (x, y, 1.f, radius);

		// Add the rigidShape to the Physics
		Physics::addObject (rigidShape);
	}

	/**
	 * Updates the entity's logic.
	 * @param deltaTime - The time elapsed since the last frame (in ms)
	 */
	void Entity::update(float deltaTime) {

	}

	/**
	 * Renders the entity to the specified window.
	 * @param window - Instance of the game window
	 */
	void Entity::render(sf::RenderWindow& window) {

		// Set shape to player rigidShape current position
		shape.setPosition(rigidShape->pos);

		// Draw shape into the screen
		window.draw(shape);
	}
}
