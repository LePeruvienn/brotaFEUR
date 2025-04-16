#ifndef BONUS_H
#define BONUS_H

#include "../core/Object.h"
#include "../stats/Effect.h"

namespace Bonus {

	/**
	 * Classed used to represent the bonuses of the game.
	 * When a Entity is interacting with them they are being granted of the bonus effect
	 */
	class Bonus : public Game::Object {

	Entity::Effect effect; ///< Bonus's effect

		/**
		 * Bonus constructor
		 * @param x - x axis position
		 * @param y - y axis position
		 * @param radius - entity body radius
		 * @param color - entity body color
		 */
		Bonus(
			float x = 50.f,
			float y = 50.f,
			float radius = 30.f,
			sf::Color color = sf::Color::Magenta,
			Entity::Effect effect = Entity::Effect()
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

	void create(
			float x = 50.f,
			float y = 50.f,
			float radius = 30.f,
			sf::Color color = sf::Color::Magenta
		);
}

#endif // BONUS_H
