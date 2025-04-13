#include "Mob.h"

namespace Mob {

	std::vector<Mob*> entities; ///< Mob entities instance list

	/**
	 * Create a new Mob entity instance, and add it to the game logic
	 * @param player - Mob instance to add to Mob entities list
	 */
	void add(Mob* mob) {

		// Add mob instance Mob entities list
		entities.push_back(mob);
	}

	/**
	 * @param y - y axis position
	 * @param radius - entity body radius
	 * @param color - entity body color
	 */
	Mob* create(float x, float y, float radius, sf::Color color, Stats stats) {
		
		// Create entity instance
		Mob* mob = new Mob(x, y, radius, color, stats);
		
		// Add Mob to entity logic
		Entity::add(mob);

		// Add mob's instance to Mob entities list
		add(mob);

		// Return Mob instance
		return mob;
	}

	/**
	 * constructs a new entity object with specified parameters.
	 * @param x - x axis position
	 * @param y - y axis position
	 * @param radius - entity body radius
	 * @param color - entity body color
	 */
	Mob::Mob(float x, float y, float radius, sf::Color color, Stats stats) 
		// Use parent's base contructor
		: Entity::Entity(x, y, radius, color, stats) {

		// Nothing to do more !
	}

	/**
	 * Updates the player's logic.
	 * @param deltaTime - The time elapsed since the last frame
	 */
	void Mob::update(float deltaTime) {

		// Use Entity update
		Entity::Entity::update (deltaTime);
	}

	/**
	 * Renders the entity to the specified window.
	 * @param window - Instance of the game window
	 */
	void Mob::render(sf::RenderWindow& window) {
		
		// Use Entity render
		Entity::Entity::render(window);
	}
}
