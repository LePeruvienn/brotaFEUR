#include "Bonus.h"

namespace Bonus {

	/**
	 * Bonus constructor
	 * @param x - x axis position
	 * @param y - y axis position
	 * @param radius - entity body radius
	 * @param color - entity body color
	 */
	Bonus::Bonus(float x, float y, float radius, sf::Color color, Entity::Effect effect)
		// Use the parent's constructor
		: Game::Object(x, y, radius, color), effect(effect) {

	};

	/**
	 * Updates the object's logic.
	 * @param deltaTime - The time elapsed since the last frame (in ms)
	 */
	void Bonus::update (float deltaTime) {

		// Use parent's update function
		Game::Object::update(deltaTime);
	};

	/**
	 * Renders the object to the specified window.
	 * @param window - Instance of the game window
	 */
	void Bonus::render(sf::RenderWindow& window) {

		// Use parent's render function
		Object::render(window);
	};
}
