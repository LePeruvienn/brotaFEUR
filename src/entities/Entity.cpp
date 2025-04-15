#include "Entity.h"
#include "../core/Physics.h"

namespace Entity {

	std::vector<Entity*> entities; ///< Game entities list

	/**
	 * Adds an new entity to the game !
	 * It adds the entity to the entities list of the game instance
	 * So the game loop will now update this entity
	 * @param entity - entity instance reference
	 */
	void add(Entity* entity) {

		// Add entity to game entities list
		entities.push_back(entity);
	}

	/**
	 * constructs a new entity object with specified parameters.
	 * @param x - x axis position
	 * @param y - y axis position
	 * @param radius - entity body radius
	 * @param color - entity body color
	 */
	Entity::Entity(float x, float y, float radius, sf::Color color, Stats stats)
		// Intialize class values
		: Game::Object(x, y, radius, color), stats(stats) {

		// Set shape position & color
		shape.setPosition({x, y});
		shape.setFillColor(color);

		// Create entity rigidShape
		rigidShape = new Physics::CircleRigidShape (x, y, 1.f, radius);

		// Add the rigidShape to the Physics
		Physics::addObject (rigidShape);
	}
}
