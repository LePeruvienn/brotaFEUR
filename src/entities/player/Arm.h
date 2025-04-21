// Force compiler to include this once
#ifndef ARM_H
#define ARM_H

#include "../../core/Object.h"

namespace Player {

	class Arm : public Game::Object {
	public:

		/**
		 * Arm class constructor
		 * @param x - start X coordinates
		 * @param y - start Y coordinates
		 * @param size - Arm size
		 */
		Arm(float x = 0.f, float y = 0.f, float size = 10.f);

		/**
		 * Updates the object's logic.
		 * @param deltaTime - The time elapsed since the last frame (in ms)
		 */
		void update(float deltaTime) override;

		/**
		 * Callback function called before the entity is deleted
		 */
		void onDestroy() override;

		/**
		 * Renders the object to the specified window.
		 * @param window - Instance of the game window
		 */
		void render(sf::RenderWindow& window) override;

	private:

		sf::RectangleShape shape;
		float size = 10.f; ///< Arm size
	};
}

#endif // ARM_H
