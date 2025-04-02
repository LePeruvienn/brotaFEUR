#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "../entities/Entity.h"
#include "../entities/Player.h"

/**
 * Singleton game instance,
 * Managing global game logic (entities, ...)
 */
class Game {
public:

	/**
	 * Singleton istance getter
	 * @return game - current game instance address
	 */
	static Game& getInstance() {
		static Game instance;
		return instance;
	}

	/**
	 * Delete copy constructors to prevent multiple instances,
	 * Used to prevent from creating new instance of Game or to change game current instance !!
	 * 
	 * Game game1 = Game::getInstance(); // OK :)
	 * Game game2 = game1;               // ERROR! Copy constructor is deleted
	 * 
	 */
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

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
	void add(Entity* entity);

	/**
	 * Set the player1 pointer to the target player
	 * @param player - player instance reference
	 */
	void setPlayer1 (Player* player);

private:

	/**
	 * Declare Game private constructors
	 * Only used with the game singleton
	 * Called when once, the first time we use getInstance();
	 */
	Game();

	/**
	 * Declare Game private desctructor
	 */
	~Game();

	/**
	 * Update game logic and entities each frame
	 * @param deltaTime - Time eleapsed between each frame
	 */
	void update(sf::Time deltaTime);

	/**
	 * Render game visual each frame
	 */
	void render();

	sf::RenderWindow window; ///< Program main window
	
	int nextId = 0; ///< Next entity added ID when added to game entities

	std::vector<Entity*> entities; ///< Game entities list

	Player* player1 = nullptr; ///< Main player entitiy pointer
};

#endif
