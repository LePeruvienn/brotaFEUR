#include "Player.h"
#include "../input/PlayerInputStates.h"
#include "../utils/Utils.h"

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

	// Nothing to do more !
}

/**
 * Updates the player's logic.
 * @param deltaTime - The time elapsed since the last frame
 */
void Player::update(float deltaTime) {

	// If user have inputs, we updateThem
	if (input) {

		// Update input
		input->update();

		// Get current inputs state
		int state = input->getState();

		// Get the current direction we are moving
		int directionX = 0;
		int directionY = 0;

		if (state & RIGHT)
			directionX++;

		if (state & LEFT)
			directionX--;

		if (state & UP)
			directionY--;

		if (state & DOWN)
			directionY++;

		// Add velocity toward the direction we are going
		velocity.x = Utils::lerp (velocity.x, speed * directionX, 0.005f);
		velocity.y = Utils::lerp (velocity.y, speed * directionY, 0.005f);
	}

	// Use Entity update
	Entity::update (deltaTime);
}

/**
 * Renders the entity to the specified window.
 * @param window - Instance of the game window
 */
void Player::render(sf::RenderWindow& window) {
	
	// Use Entity render
	Entity::render(window);
}

/**
 * Adds user control to the player
 */
void Player::addInput () {

	// Set a new unique PlayerInput
    input = std::make_unique<PlayerInput>();
}
