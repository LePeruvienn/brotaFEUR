// Fore the compiler to include this once
#ifndef MOB_H
#define MOB_H

#include "../Entity.h"

namespace Mob {

	/**
	 * Mob entity who will be controlled by a mob
	 * Chlid class from the Entity class
	 */
	class Mob : public ::Entity::Entity {
	public:

		/**
		 * constructs a new entity object with specified parameters.
		 * @param x - x axis position
		 * @param y - y axis position
		 * @param radius - entity body radius
		 * @param color - entity body color
		 */
		Mob(
			float x,
			float y,
			float radius = 30.f,
			sf::Color color = sf::Color::Red,
			::Entity::Stats stats = ::Entity::Stats() // We must add :: that specifiy the compiler to just start on top of everything 
		);	                                          // and dont search this Into the Entity namespace already

		/**
		 * Updates the mob's logic.
		 * @param deltaTime - The time elapsed since the last frame (in ms)
		 */
		void update(float deltaTime) override;

		/**
		 * Renders the mob to the specified window.
		 * @param window - Instance of the game window
		 */
		void render(sf::RenderWindow& window) override;
	};

	extern std::vector<Mob*> entities; ///< Mob entities instance list

	/**
	 * Create a new Mob entity instance, and add it to the game logic
	 * @param player - Mob instance to add to Mob entities list
	 */
	void add(Mob* mob);

	/**
	 * Create a Mob instance and add it to the game logic
	 * @param x - x axis position
	 * @param y - y axis position
	 * @param radius - entity body radius
	 * @param color - entity body color
	 */
	Mob* create(
		float x,
		float y,
		float radius = 30.f,
		sf::Color color = sf::Color::Red,
		::Entity::Stats stats = ::Entity::Stats() // We must add :: that specifiy the compiler to just start on top of everything 
	);	                                          // and dont search this Into the Entity namespace already
}

#endif // MOB_H
