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
}
