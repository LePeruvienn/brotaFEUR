#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Stats.h"
#include "../core/rigidShapes/RigidShape.h"
#include "../core/rigidShapes/CircleRigidShape.h"

/**
 * Abstract class representing a generic entity in the game
 *
 * This class serves as a base for all entities that can be rendered and updated
 * in the game. It provides basic functionality for position and shape
 */
class Entity {
public:

	int id = -1; ///< Entity game unique ID. Is set when the entity is added to the game, is equel to -1 if not set
	Stats stats; /// < Stats class to handle all entiteis stats

	/**
	 * constructs a new entity object with specified parameters.
	 * @param x - x axis position
	 * @param y - y axis position
	 * @param radius - entity body radius
	 * @param color - entity body color
	 * @param stats - entities stats
	 */
	Entity(
		float x = 50.f,
		float y = 50.f,
		float radius = 30.f,
		sf::Color color = sf::Color::Green,
		Stats stats = Stats ()
	);

	/**
	 * Virtual destructor for the Entity class.
	 * This ensures that derived classes' destructors are called properly
	 */
	virtual ~Entity() = default;

	/**
	 * Updates the entity's logic.
	 * @param deltaTime - The time elapsed since the last frame (in ms)
	 */
	virtual void update(float deltaTime);

	/**
	 * Renders the entity to the specified window.
	 * @param window - Instance of the game window
	 */
	virtual void render(sf::RenderWindow& window);

protected:
	sf::CircleShape shape; ///< Shape representing the entity.
	Physics::RigidShape* rigidShape = nullptr; //< RigidShape linked to the entity
};

#endif // ENTITY_H
