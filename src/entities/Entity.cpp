#include "Entity.h"

/**
 * constructs a new entity object with specified parameters.
 * @param x - x axis position
 * @param y - y axis position
 * @param radius - entity body radius
 * @param color - entity body color
 */
Entity::Entity(float x, float y, float radius, sf::Color color) {

	// Set entity position
	pos.x = x;
	pos.y = y;

	// Set velocity to 0 by default
	velocity.x = 0.f;
	velocity.y = 0.f;

	// Set speed to 0.2f by default
	speed = 0.2f;

	// Create Shape
	shape = sf::CircleShape(radius);
	
	// Update shape position & color
	shape.setPosition(pos);
	shape.setFillColor(color);
}

/**
 * Updates the entity's logic.
 * @param deltaTime - The time elapsed since the last frame (in ms)
 */
void Entity::update(float deltaTime) {

	// Update pos depending on player's velocity
	pos.x += deltaTime * velocity.x;
	pos.y += deltaTime * velocity.y;
}

/**
 * Renders the entity to the specified window.
 * @param window - Instance of the game window
 */
void Entity::render(sf::RenderWindow& window) {

	// Set shape to player current position
	shape.setPosition(pos);

	// Draw shape into the screen
	window.draw(shape);
}
