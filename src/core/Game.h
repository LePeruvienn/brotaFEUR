// Fore the compiler to include this once
#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Scene.h"
#include "Object.h"
#include "../entities/Entity.h"
#include "../entities/player/Player.h"

/**
 * Game Module
 * Managing global game logic (entities, ...)
 */

/** @module Game */
namespace Game {

	extern sf::RenderWindow window; ///< Program main window

	extern Scene* currentScene; ///< Current game scene active
	extern std::unordered_map<std::string, Scene*> scenes; ///< All game available scenes

	extern Player::Player* player1; ///< Main player entitiy pointer

	extern unsigned int nextId; ///< Next object added ID when added to game objects
	extern std::vector<Object*> objects; ///< Game objects list


	extern std::vector<Object*> cachedObjectsToDelete; ///< Cached array that store all the objects we must delete at the end of the loop

	/**
	 * Initialize the Game module
	 */
	void init ();

	/**
	 * Run the game main loop
	 */
	void run();

	/**
	 * Quit the game, stop the game loop & program
	 */
	void exit();

	/*
	 * Change current game scene
	 * @param name - target scene name
	 */
	void setScene(std::string& name);

	/**
	 * Add a game object to the objects list
	 * @param Object*
	 */
	void add(Object* gameObject);

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

#endif // GAME_H
