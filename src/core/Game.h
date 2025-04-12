#pragma once ///< Fore the compiler to include this once

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../entities/Entity.h"
#include "../entities/player/Player.h"

/**
 * Game Module
 * Managing global game logic (entities, ...)
 */
namespace Game {

	extern sf::RenderWindow window; ///< Program main window
	
	extern unsigned int nextId; ///< Next entity added ID when added to game entities

	extern std::vector<Entity::Entity*> entities; ///< Game entities list

	extern Player::Player* player1; ///< Main player entitiy pointer

	/**
	 * Initialize the Game module
	 */
	void init ();

	/**
	 * Run the game main loop
	 */
	void run();

	/**
	 * Adds an new entity to the game !
	 * It adds the entity to the entities list of the game instance
	 * So the game loop will now update this entity
	 * @param entity - entity instance reference
	 */
	void add(Entity::Entity* entity);

	/**
	 * Set the player1 pointer to the target player
	 * @param player - player instance reference
	 */
	void setPlayer1 (Player::Player* player);

	/**
	 * Update game logic and entities each frame
	 * @param deltaTime - Time eleapsed between each frame
	 */
	void update(sf::Time deltaTime);

	/**
	 * Render game visual each frame
	 */
	void render();

	/**
	 * Flush the game module
	 */
	void flush();
}
