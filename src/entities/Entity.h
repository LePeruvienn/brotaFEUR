#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

/**
 * Abstract class representing a generic entity in the game
 *
 * This class serves as a base for all entities that can be rendered and updated
 * in the game. It provides basic functionality for position and shape
 */
class Entity {
public:
	/**
	 * constructs a new entity object with specified parameters.
	 * @param x - x axis position
	 * @param y - y axis position
	 * @param radius - entity body radius
	 * @param color - entity body color
	 */
	Entity(float x = 50.f, float y = 50.f, float radius = 30.f, sf::Color color = sf::Color::Green);

	/**
	 * Virtual destructor for the Entity class.
	 * This ensures that derived classes' destructors are called properly
	 */
	virtual ~Entity() = default;

	/**
	 * Updates the entity's logic.
	 * @param deltaTime - The time elapsed since the last frame
	 */
	virtual void update(sf::Time deltaTime);

	/**
	 * Renders the entity to the specified window.
	 * @param window - Instance of the game window
	 */
	virtual void render(sf::RenderWindow& window);

protected:
	sf::Vector2f pos; ///< Current position of the entity.
	sf::CircleShape shape; ///< Shape representing the entity.
};

#endif // ENTITY_H
