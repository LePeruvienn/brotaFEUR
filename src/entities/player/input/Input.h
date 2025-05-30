// Force compiler to include this once
#ifndef INPUT_H
#define INPUT_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "InputStates.h"

/** @module Player */
namespace Player {

	/**
	 * PlayerInput is use to handle user input on players
	 * Each player can have an associated input on player.addInput();
	 */
	class Input {
	public:

		/**
		 * Class constructor
		 * No parameter yet => To improve to link each player some inputs
		 */
		Input();

		/**
		 * Update current input state
		 */
		void update ();

		/**
		 * Get current input state
		 * @return state
		 */
		int getState ();

		/**
		 * Get current player input direction
		 * @return Vector2i - direction x & y
		 */
		sf::Vector2i getDirection();

	private:
		int state; //< Current input state
	};
}

#endif // INPUT_H
