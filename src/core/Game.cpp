#include "Game.h"
#include <optional>
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
	delete player1;
	for (Entity* entity : entities) {
		delete entity;
	}
}

/**
 * Run the game main loop
 */
void Game::run() {

	sf::Clock clock;

	// Game Loop
	while (window.isOpen()) {
		sf::Time deltaTime = clock.restart();
		processInput();
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
	
	player1 = player;
}

/**
 * Handle users inputs !
 */
void Game::processInput() {

	while (const std::optional event = window.pollEvent())
	{
		if (event->is<sf::Event::Closed>())
		{
			window.close();
		}
	}
}

/**
 * Update game logic and entities each frame
 * @param deltaTime - Time eleapsed between each frame
 */
void Game::update(sf::Time deltaTime) {
	for (auto& entity : entities) {
		entity->update(deltaTime);
	}
}

/**
 * Render game visual each frame
 */
void Game::render() {

	window.clear(sf::Color::Black);
	for (auto& entity : entities) {
		entity->render(window);
	}
	window.display();
}
