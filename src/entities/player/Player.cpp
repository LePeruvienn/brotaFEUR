#include <cmath>
#include "Player.h"
#include "InputStates.h"
#include "../../utils/Utils.h"

using namespace Entity;

namespace Player {

	/**
	 * constructs a new entity object with specified parameters.
	 * @param x - x axis position
	 * @param y - y axis position
	 * @param radius - entity body radius
	 * @param color - entity body color
	 */
	Player::Player(float x, float y, float radius, sf::Color color, Stats stats) 
		// Use parent's base contructor
		: Entity(x, y, radius, color, stats) {

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

			// If we are moving in diagonal
			if (directionX != 0 && directionY != 0) {

				// Compute diagonalFactor
				float diagonalFactor = 1 / std::sqrt(2.f);

				// Fix direction
				directionX /= diagonalFactor;
				directionY /= diagonalFactor;
			}

			// Defining lerp value for velocity
			float lerp = 0.005f;

			// Add velocity toward the direction we are going
			rigidShape->velocity.x = Utils::lerp (rigidShape->velocity.x, stats.speed * directionX, lerp);
			rigidShape->velocity.y = Utils::lerp (rigidShape->velocity.y, stats.speed * directionY, lerp);
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
		// (make that if there is already have a Player input it delete the old and set a new one )
		// => NO MEMORY LEAK
		input = std::make_unique<Input>();
	}
}
