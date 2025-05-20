#include <iostream>
#include "Game.h"
#include "Physics.h"
#include "../cli/Console.h"
#include "../entities/mob/Mob.h"

/** @module Game */
namespace Game {

	sf::RenderWindow window; ///< Program main window

	Scene* currentScene = nullptr; ///< Current game scene active
	std::unordered_map<std::string, Scene*> scenes; ///< All game available scenes

	Player::Player* player1 = nullptr; ///< Main player entitiy pointer
		
	unsigned int nextId = 0; ///< Next object added ID when added to game objects

	/**
	 * Declare Game private constructors
	 * Only used with the game singleton
	 * Called when once, the first time we use getInstance();
	 */
	void init() {

		// Create game window
		window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
		// YEEEY game instance initialized B)
		Console::log("Game instance initialized !\n");

		// Create a new scene named `default`
		currentScene = new Scene("default");

		// Init current scene
		currentScene->init(window);
	}

	/**
	 * Run the game main loop
	 */
	void run() {

		// Get sfml clock
		sf::Clock clock;

		// Game Loop
		while (window.isOpen()) {

			// Get current deltaTime
			sf::Time deltaTime = clock.restart();

			update(deltaTime);
			render();
		}
	}

	/**
	 * Add a game object to the objects list
	 * @param Object*
	 */
	void add (Object* object) {

		// Addd gameObject to objects list
		currentScene->add(object);
	}

	/**
	 * Set the player1 pointer to the target player
	 * @param player - player instance reference
	 */
	void setPlayer1 (Player::Player* player) {
		
		// Set player1 instance
		player1 = player;
	}

	/**
	 * Update game logic and entities each frame
	 * @param deltaTime - Time eleapsed between each frame
	 */
	void update(sf::Time deltaTime) {

		// Convert dt in ms (we convert um so ms to have more precision)
		float dt = deltaTime.asMicroseconds() / 1000.0f;

		// Update game's physic
		Physics::update(dt);

		// Updates others modules
		Mob::update(dt);
		
		// Update current scene objects
		currentScene->update(dt);
	}

	/**
	 * Render game visual each frame
	 */
	void render() {

		// Draw background
		window.clear(sf::Color::Black);

		// Make the camera follow player 1
		// Maybe make the camera adapt to screen size ?
		// Not used yet cause it's not usefull
		// if (player1 != nullptr)
			// currentScene->camera.setCenter(player1->pos);

		// Render current scenes objects
		currentScene->render(window);

		// Update display
		window.display();
	}

	/**
	 * Flush the Game module
	 */
	void flush() {

		// Delete player1
		delete player1;
	}
}

