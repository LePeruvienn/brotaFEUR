#include <cmath>
#include "Mob.h"
#include "../../core/Game.h"
#include "../player/Player.h"

using Entity::Stats; // So we can declare Stats like this : Stats();

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
	 * Create a Mob instance and add it to the game logic
	 * @param x - x axis position
	 * @param y - y axis position
	 * @param radius - entity body radius
	 * @param color - entity body color
	 */
	Mob* create(float x, float y, float radius, sf::Color color, Stats stats) {
		
		// Create entity instance
		Mob* mob = new Mob(x, y, radius, color, stats);

		// Add instance to game object list
		Game::add(mob);
		
		// Add Mob to entity logic
		Entity::add(mob);

		// Add mob's instance to Mob entities list
		add(mob);

		// Return Mob instance
		return mob;
	}

	/**
	 * Return the closest mob alive next to the targetPos
	 * @param targetPos - vector x & y of the position we want a mob close
	 * @return Mob* - the pointer of the closest mob
	 */
	Mob* getClosestTo(sf::Vector2f targetPos) {

		// Create max founded vars
		Mob* closest = nullptr;
		float lastDistance = MAXFLOAT;

		// We search for a mob in the Mob::entities array
		for (int i = 0; i < entities.size(); i++) {

			// Compute distance
			float dx = entities[i]->pos.x - targetPos.x;
			float dy = entities[i]->pos.y - targetPos.y;
			float distance = dx * dx + dy * dy;

			// If current distance is not less than last, go to next mob
			if (distance >= lastDistance) continue;

			// If current distance is less that last distance ! Update last & closest values 🥷
			lastDistance = distance;
			closest = entities[i];
		}
		
		// Return closest mob
		return closest;
	};

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

		// If Player player1 is defined we move toward him
		if (Player::player1 != nullptr) {
			
			// Get Player1 pos
			float playerX = Player::player1->rigidShape->pos.x;
			float playerY = Player::player1->rigidShape->pos.y;
		
			// Get current Mob's pos
			float x = rigidShape->pos.x;
			float y = rigidShape->pos.y;

			// Compute angle
			float angle = std::atan2(playerY - y, playerX - x);

			// Update rigidShape velocity
			rigidShape->velocity.x = std::cos(angle) * stats.speed * 0.5f;
			rigidShape->velocity.y = std::sin(angle) * stats.speed * 0.5f;
		}
	}

	/*
	 * Callback function called before the entity is deleted
	 */
	void Mob::onDestroy() {

		/*
		 * OPTIMIZE: We are looping all the entities loop for 1 entity,
		 * Maybe each frame we could loop once for each entites ? IDK 🤓
		 */

		// Search for current entity as remove it from the array
		for (int i = 0; i < entities.size(); i++) {
			
			// If we found current entity
			if (entities[i]->id == id) {
				
				// Erase it from entities array
				entities.erase(entities.begin() + i);

				// Go out the for loop
				break;
			}
		}

		// Use parent's function
		Entity::onDestroy();
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
