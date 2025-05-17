#include <string>
#include <vector>
#include "Object.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

/** @module Game */
namespace Game {

	class Scene {
	public:

		sf::View camera; ///< Scene camera

		/**
		 * Scene constructor
		 */
		Scene(std::string name);

		/**
		 * Scene update loop
		 * @param deltaTime
		 */
		 void init(sf::RenderWindow& window);

		/**
		 * Scene update loop
		 * @param deltaTime
		 */
		void update(float deltaTime); ///< Update loop of current scene

		/**
		 * Renders the object to the specified window.
		 * @param window - Instance of the game window
		 */
		 void render(sf::RenderWindow& window);

		/**
		 * Add an object to the scene
		 * @param Object* - game object we want to add
		 */
		void add(Object* object);

		/**
		 * Remove an object from the scene
		 * @param Object* - game object we want to add
		 */
		void remove(Object* object);

		/**
		 * Scene name getter
		 * @return string - scene name
		 */
		std::string getName() const;

		/**
		 * Flush the scene instance
		 */
		void flush();

	private:

		std::string name; ///< Scene name
		
		std::vector<Object*> objects; ///< Scene currents objects

		std::vector<Object*> cachedObjectsToDelete; ///< Cached array that store all the objects we must delete at the end of the loop
	};
}
