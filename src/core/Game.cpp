#include "Game.h"
#include <iostream>

/**
 * Declare Game private constructors
 * Only used with the game singleton
 * Called when once, the first time we use getInstance();
 */
Game::Game() {

	// Create game window
	window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
	// YEEEY game instance initialized B)
	std::cout << "Game instance initialized !\n";
}

/**
 * Declare Game private desctructor
 * Used to delete reference of all the entities and player1
 */
Game::~Game() {

	// Delete player1
	delete player1;

	// Delete each game entity
	for (Entity* entity : entities) {
		delete entity;
	}
}

/**
 * Run the game main loop
 */
void Game::run() {

	// Get sfml clock
	sf::Clock clock;

	// Game Loop
	while (window.isOpen()) {

		// Get  current deltaTime
		sf::Time deltaTime = clock.restart();

		update(deltaTime);
		render();
	}
}

/**
 * Adds an new entity to the game !
 * It adds the entity to the entities list of the game instance
 * So the game loop will now update this entity
 * @param entity - entity instance reference
 */
void Game::add(Entity* entity) {

	// Set entity ID
	entity->id = nextId;

	// Increment next ID
	nextId++;

	// Add entity to game entities list
	entities.push_back(entity);
}

/**
 * Set the player1 pointer to the target player
 * @param player - player instance reference
 */
void Game::setPlayer1 (Player* player) {
	
	// Set player1 instance
	player1 = player;
}

/**
 * Update game logic and entities each frame
 * @param deltaTime - Time eleapsed between each frame
 */
void Game::update(sf::Time deltaTime) {
	
	// Convert dt in ms (we convert um so ms to have more precision)
	float dt = deltaTime.asMicroseconds() / 1000.0f;
	
	// Update all entities logic
	for (auto& entity : entities) {
		entity->update(dt);
	}
}

/**
 * Render game visual each frame
 */
void Game::render() {

	// Draw background
	window.clear(sf::Color::Black);

	// Render each entity
	for (auto& entity : entities) {
		entity->render(window);
	}

	// Update display
	window.display();
}
