#include <cmath>
#include <new>
#include <iostream>
#include "Player.h"
#include "../mob/Mob.h"
#include "../../core/Game.h"
#include "../../utils/Utils.h"
#include "../../objects/Projectile.h"

using Entity::Stats; // So we can declare Stats like this : Stats();

/** @module Player */
namespace Player {

	std::vector<Player*> entities; ///< Player entities list

	Player* player1 = nullptr; ///< Player 1 instance

	/**
	 * Set player instance in param to player1
	 * @param player - Player1 instance
	 */
	void setPlayer1(Player* player) {

		// Set player1 instance to player
		player1 = player;
	}

	/*
	 * Create a new Player entity instance, and add it to the game logic
	 * @param player - Player instance to add to Player entities list
	 */
	void add (Player* player) {

		// Add entity to game entities list
		entities.push_back(player);
	}

	/**
	 * Create a new Player entity instance, and add it to the game logic
	 * @param x - x axis position
	 * @param y - y axis position
	 * @param radius - entity body radius
	 * @param color - entity body color
	 * @return Player* - return the pointer of the player instance
	 */
	Player* create(float x, float y, float radius, sf::Color color, Stats stats) {

		// create Player instance
		Player* player = new Player(x, y, radius, color, stats);

		// Add instance to game object list
		Game::add(player);

		// Add Instance to entities list
		Entity::add(player);
		
		// Add instance to Player entities list
		add(player);

		// Return player instance
		return player;
	}

	/**
	 * constructs a new entity object with specified parameters.
	 * @param x - x axis position
	 * @param y - y axis position
	 * @param radius - entity body radius
	 * @param color - entity body color
	 */
	Player::Player(float x, float y, float radius, sf::Color color, Stats stats) 
		// Use parent's base contructor
		: Entity::Entity(x, y, radius, color, stats) {

		// Nothing to do more !
	}

	/**
	 * Updates the player's logic.
	 * @param deltaTime - The time elapsed since the last frame
	 */
	void Player::update(float deltaTime) {

		// Handle player movement & shooting
		handleMovement();
		handleShooting(deltaTime);
	}

	/**
	 * Renders the entity to the specified window.
	 * @param window - Instance of the game window
	 */
	void Player::render(sf::RenderWindow& window) {
		
		// Use Entity render
		Entity::Entity::render(window);
	}

	/*
	 * Callback function called before the entity is deleted
	 */
	void Player::onDestroy() {

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
	 * Adds user control to the player
	 */
	void Player::addInput () {

		// Set a new unique PlayerInput 
		// (make that if there is already have a Player input it delete the old and set a new one )
		// => NO MEMORY LEAK
		input = std::make_unique<Input>();
	}

	/**
	 * Handle player movement depending of his inputs
	 */
	void Player::handleMovement() {

		// If user have inputs, we updateThem
		if (input) {

			// Update input
			input->update();

			// Get current inputs state
			sf::Vector2i direction = input->getDirection();

			// If we are moving in diagonal
			if (direction.x != 0 && direction.y != 0) {

				// Compute diagonalFactor
				float diagonalFactor = 1 / std::sqrt(2.f);

				// Fix direction
				direction.x /= diagonalFactor;
				direction.y /= diagonalFactor;
			}

			// Defining lerp value for velocity
			float lerp = 0.005f;

			// Add velocity toward the direction we are going
			rigidShape->velocity.x = Utils::lerp (rigidShape->velocity.x, stats.speed * direction.x, lerp);
			rigidShape->velocity.y = Utils::lerp (rigidShape->velocity.y, stats.speed * direction.y, lerp);
		}
	}

	/**
	 * Handle player shooting
	 * @parm deltaTime - used to compute firerate
	 */
	void Player::handleShooting(float deltaTime) {

		// If the shotTimer has reached his end
		if (shotTimer >= shootCoolown) {

			// Get closest Mob from current pos
			Mob::Mob* mob = Mob::getClosestTo(pos);

			// If we found a mob !
			if (mob != nullptr) {

				// Get current player postion
				float x = rigidShape->pos.x;
				float y = rigidShape->pos.y;

				// Compute direction
				float dx = mob->rigidShape->pos.x - x;
				float dy = mob->rigidShape->pos.y - y;

				// Normalize direction !
				// OPTIMIZE: sqrt() is heavy maybe use Q_rsqrt() from DOOM to optimize this 👀
				float length = sqrt(dx * dx + dy * dy);
				// Avoid division by zero
				if (length > 0.f) {
					// Apply normalization
					dx /= length;
					dy /= length;
				}

				// Shoot a projectile toward this direction
				Projectile::create(x, y, dx, dy);

				// Reset shotTimer
				shotTimer = 0.f;
			}
		}

		// Increment shotTimer
		shotTimer += deltaTime;
	}
}
