#include "Game.h"
#include "Physics.h"
#include <iostream>

namespace Game {

	sf::RenderWindow window; ///< Program main window

	Player::Player* player1 = nullptr; ///< Main player entitiy pointer
		
	unsigned int nextId = 0; ///< Next object added ID when added to game objects
	std::vector<Object*> objects; ///< Game objects list

	/**
	 * Declare Game private constructors
	 * Only used with the game singleton
	 * Called when once, the first time we use getInstance();
	 */
	void init() {

		// Create game window
		window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
		// YEEEY game instance initialized B)
		std::cout << "Game instance initialized !\n";
	}

	/**
	 * Run the game main loop
	 */
	void run() {

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
	 * Add a game object to the objects list
	 * @param Object*
	 */
	void add (Object* gameObject) {

		// Set game object ID
		gameObject->id = nextId;

		// Increment nextId
		nextId++;

		// Addd gameObject to objects list
		objects.push_back (gameObject);
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
		
		// Update all entities logic
		for (int i = 0; i < Game::objects.size ();) {

			// Get current object
			Object* currentObject = Game::objects[i]; 
	
			// If object has to be deleted, we dont update it
			if (currentObject->getToBeDeleted() == true) {

				// Remove current object from the list
				Game::objects.erase(Game::objects.begin() + i);

				// Delete object from the game logic & memory
				currentObject->_destroy(); /// CAUTION THIS DELETE THE OBJECT FROM MEMORY

				// Go to next object
				continue;
			}

			// Update current object
			currentObject->update(dt);

			// Increment i before going to the next object
			i++;
		}
	}

	/**
	 * Render game visual each frame
	 */
	void render() {

		// Draw background
		window.clear(sf::Color::Black);

		// Render each entity
		for (auto& object : Game::objects) {
			object->render(window);
		}

		// Update display
		window.display();
	}

	/**
	 * Flush the Game module
	 */
	void flush() {

		// Delete player1
		delete player1;

		// Delete each game entity
		for (Entity::Entity* entity : Entity::entities) {
			delete entity;
		}
	}
}

