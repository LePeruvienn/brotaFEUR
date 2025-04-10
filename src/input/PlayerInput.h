#ifndef PLAYERINPUT_H
#define PLAYERINPUT_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "PlayerInputStates.h"

/**
 * PlayerInput is use to handle user input on players
 * Each player can have an associated input on player.addInput();
 */
class PlayerInput {
public:

	/**
	 * Class constructor
	 * No parameter yet => To improve to link each player some inputs
	 */
	PlayerInput();

	/**
	 * Update current input state
	 */
	void update ();

	/**
	 * Get current input state
	 * @return state
	 */
	int getState ();

private:
	int state; //< Current input state
};

#endif // PLAYERINPUT_H
