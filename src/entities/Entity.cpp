#include "Entity.h"

/**
 * constructs a new entity object with specified parameters.
 * @param x - x axis position
 * @param y - y axis position
 * @param radius - entity body radius
 * @param color - entity body color
 */
Entity::Entity(float x, float y, float radius, sf::Color color) {

	// Set the shape & pos properties
	pos = sf::Vector2f(x, y);
	shape = sf::CircleShape(radius);
	// Update shape position & color
	shape.setPosition(pos);
	shape.setFillColor(color);
}

/**
 * Updates the entity's logic.
 * @param deltaTime - The time elapsed since the last frame
 */
void Entity::update(sf::Time deltaTime) {
	// No logic to update by default
}

/**
 * Renders the entity to the specified window.
 * @param window - Instance of the game window
 */
void Entity::render(sf::RenderWindow& window) {
	window.draw(shape);
}
