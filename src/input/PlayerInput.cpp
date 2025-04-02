#include "PlayerInput.h"
#include "PlayerInputStates.h"
#include <iostream>

/**
 * Class constructor
 * No parameter yet => To improve to link each player some inputs
 */
PlayerInput::PlayerInput () {

	// State is 0 by default
	state = 0;
}

/**
 * Update current input state
 */
void PlayerInput::update () {

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
int PlayerInput::getState () {

	// Return current state
	return state;
}
