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

	/** Private variables */
	namespace {

		bool exitGame = false; ///< Must we exit the game ?
	}

	/**
	 * Declare Game private constructors
	 * Only used with the game singleton
	 * Called when once, the first time we use getInstance();
	 */
	void init() {

		// Create game window
		window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");

		// Create a new scene named `default`
		currentScene = new Scene("default");

		// Save the default scene to map
		scenes[currentScene->getName()] = currentScene;

		// Add others scenes ...
		scenes["menu"] = new Scene("menu");

		// Init current scene
		currentScene->init(window);
	}

	/**
	 * Run the game main loop
	 */
	void run() {

		// Get SFML clock
		sf::Clock clock;

		// Game Loop
		while (window.isOpen()) {

			// if we must qui the game go out of the loop
			if (exitGame)
				break;

			// Get current deltaTime
			sf::Time deltaTime = clock.restart();

			// update Game
			update(deltaTime);

			// Render Game
			render();
		}
	}

	/**
	 * Exit the game, stop the game loop & program
	 */
	void exit() {

		// Set exitGame to true
		exitGame = true;
	}

	/*
	 * Change current game scene
	 * @param name - target scene name
	 */
	void setScene(std::string& name) {

		// If we find the current scene
		if (scenes.find(name) != scenes.end())
			// Set new scene to scene name
			currentScene = scenes[name];

		// If we dont find we log an error
		else 
			Console::logError("The scene `" + name + "` does not exist");
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

