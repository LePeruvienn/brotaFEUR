#include <vector>
#include "Camera.h"
#include "../Object.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

/** @module Game */
namespace Game {

	class Scene {
	public:

		/**
		 * Scene constructor
		 */
		Scene();

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
		 * Flush the scene instance
		 */
		void flush();

		/**
		 * Camera setter
		 */
		void getCamera();
	
		/**
		 * Set current camera
		 * @param _camera - new camera to set
		 */
		void setCamera(Camera* _camera);

	private:
		
		std::vector<Object*> objects; ///< Scene currents objects

		std::vector<Object*> cachedObjectsToDelete; ///< Cached array that store all the objects we must delete at the end of the loop
	
		Camera* camera = nullptr; ///< Current scene active Camera
	};
}
