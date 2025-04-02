#include "Player.h"

/**
 * constructs a new entity object with specified parameters.
 * @param x - x axis position
 * @param y - y axis position
 * @param radius - entity body radius
 * @param color - entity body color
 */
Player::Player(float x, float y, float radius, sf::Color color) 
	// Use parent's base contructor
	: Entity(x, y, radius, color) {
	
	// Update velocity
	velocity.x = 0.2f;
	velocity.y = 0.2f;
}

/**
 * Updates the player's logic.
 * @param deltaTime - The time elapsed since the last frame
 */
void Player::update(float deltaTime) {

	pos.x += deltaTime * velocity.x;
	pos.y += deltaTime * velocity.y;
}

/**
 * Renders the entity to the specified window.
 * @param window - Instance of the game window
 */
void Player::render(sf::RenderWindow& window) {

	shape.setPosition(pos);

	Entity::render(window);
}
