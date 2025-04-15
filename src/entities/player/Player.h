// Fore the compiler to include this once
#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
#include "../Entity.h"
#include "Input.h"

namespace Player {

	/**
	 * Player entity who will be controlled by a player
	 * Chlid class from the Entity class
	 */
	class Player : public ::Entity::Entity {
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
			::Entity::Stats stats = ::Entity::Stats() // We must add :: that specifiy the compiler to just start on top of everything 
		);	                                          // and dont search this Into the Entity namespace already

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

	extern Player* player1; ///< Player 1 instance

	/**
	 * Create a new Player entity instance, and add it to the game logic
	 * @param player - Player instance to add to Player entities list
	 */
	void add(Player* player);

	/**
	 * Set player instance in param to player1
	 * @param player - Player1 instance
	 */
	void setPlayer1 (Player* player);

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
		::Entity::Stats stats = ::Entity::Stats() // We must add :: that specifiy the compiler to just start on top of everything 
	);	                                          // and dont search this Into the Entity namespace already

}

#endif // PLAYER_H
