#ifndef BONUS_H
#define BONUS_H

#include "../core/Object.h"

namespace {

	class Bonus : public Game::Object {

		Bonus(
			float x = 50.f,
			float y = 50.f,
			float radius = 30.f,
			sf::Color color = sf::Color::Magenta
		);

		/**
		 * Updates the object's logic.
		 * @param deltaTime - The time elapsed since the last frame (in ms)
		 */
		void update(float deltaTime) override;

		/**
		 * Renders the object to the specified window.
		 * @param window - Instance of the game window
		 */
		void render(sf::RenderWindow& window) override;

	};
}

#endif // BONUS_H
