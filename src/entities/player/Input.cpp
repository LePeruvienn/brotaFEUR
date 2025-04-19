#include "Input.h"
#include "InputStates.h"

namespace Player {

	/**
	 * Class constructor
	 * No parameter yet => To improve to link each player some inputs
	 */
	Input::Input () {

		// State is 0 by default
		state = 0;
	}

	/**
	 * Update current input state
	 */
	void Input::update () {

		// reset current state
		state = 0;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
			state |= LEFT;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
			state |= RIGHT;
			
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
			state |= UP;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
			state |= DOWN;
	}

	/**
	 * Get current input state
	 * @return state
	 */
	int Input::getState () {

		// Return current state
		return state;
	}

	/**
	 * Get current player input direction
	 * @return Vector2i - direction x & y
	 */
	sf::Vector2i Input::getDirection() {

		// Get the current direction we are moving
		int directionX = 0;
		int directionY = 0;

		// Compute direction
		if (state & RIGHT)
			directionX++;
		if (state & LEFT)
			directionX--;
		if (state & UP)
			directionY--;
		if (state & DOWN)
			directionY++;

		// Return current player input direction
		return sf::Vector2i(directionX, directionY);
	}
}
