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
	
	// Nothing to do yet
}

/**
 * Updates the player's logic.
 * @param deltaTime - The time elapsed since the last frame
 */
void Player::update(sf::Time deltaTime) {

	// Noting to do yet
}
