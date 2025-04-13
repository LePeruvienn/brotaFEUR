#pragma once ///< Fore the compiler to include this once

#include <memory>
#include "../Entity.h"
#include "Input.h"

using namespace Entity;

namespace Player {

	/**
	 * Player entity who will be controlled by a player
	 * Chlid class from the Entity class
	 */
	class Player : public Entity {
	public:

		/**
		 * constructs a new entity object with specified parameters.
		 * @param x - x axis position
		 * @param y - y axis position
		 * @param radius - entity body radius
		 * @param color - entity body color
		 */
		Player(
			float x,
			float y,
			float radius = 30.f,
			sf::Color color = sf::Color::Blue,
			Stats stats = Stats()
		);

		/**
		 * Updates the player's logic.
		 * @param deltaTime - The time elapsed since the last frame (in ms)
		 */
		void update(float deltaTime) override;

		/**
		 * Renders the player to the specified window.
		 * @param window - Instance of the game window
		 */
		void render(sf::RenderWindow& window) override;

		/**
		 * Adds user control to the player
		 */
		void addInput();

	private:
		std::unique_ptr<Input> input; //< Each Player has one unique PlayerInput
	};

	extern std::vector<Player*> entities; ///< Player entities list

	/**
	 * Create a new Player entity instance, and add it to the game logic
	 * @param player - Player instance to add to Player entities list
	 */
	void add (Player* player);

	/**
	 * Create a new Player entity instance, and add it to the game logic
	 * @param x - x axis position
	 * @param y - y axis position
	 * @param radius - entity body radius
	 * @param color - entity body color
	 * @return Player* - return the pointer of the player instance
	 */
	Player* create(
		float x,
		float y,
		float radius = 30.f,
		sf::Color color = sf::Color::Blue,
		Stats stats = Stats()
	);

}
