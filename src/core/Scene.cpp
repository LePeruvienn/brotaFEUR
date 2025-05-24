#include "Scene.h"

/** @module Game */
namespace Game {

	/**
	 * Scene constructor
	 */
	Scene::Scene (std::string name) : name(name) {}

	/**
	 * Scene update loop
	 * @param deltaTime
	 */
	void Scene::init(sf::RenderWindow& window) {

		// Get current window size
		sf::Vector2u size = window.getSize();
		
		// Cast values as floats
		float width = static_cast<float>(size.x);
		float height = static_cast<float>(size.y);

		// Create camera view
		camera = sf::View(sf::FloatRect(
			{ 0.f, 0.f }, // View pos
			{ width, height } /// View width & height
		));

		// Zoom into the view
		camera.zoom(1.f);

		// Set camera view
		window.setView(camera);
	}

	/**
	 * Scene update loop
	 * @param deltaTime
	 */
	void Scene::update(float deltaTime) {

		// Reset cachedObjectsToDelete to use it !
		cachedObjectsToDelete.clear();
		
		// Update all entities logic
		for (int i = 0; i < objects.size ();) {

			// Get current object
			Object* currentObject = objects[i]; 
	
			// If object has to be deleted, we dont update it
			if (currentObject->getToBeDeleted() == true) {

				// Remove current object from the list
				objects.erase(objects.begin() + i);

				// Delete object from the game logic & memory
				currentObject->_destroy(); /// CAUTION THIS DELETE THE OBJECT FROM MEMORY
			
				// add it to the objects to delete Array
				cachedObjectsToDelete.push_back(currentObject);

				// Go to next object
				continue;
			}

			// Update current object
			currentObject->update(deltaTime);

			// Increment i before going to the next object
			i++;
		}

		// Delete from memory all objects to delete
		for (int i = 0; i < cachedObjectsToDelete.size(); i++)
			delete cachedObjectsToDelete[i];
	}

	/**
	 * Renders the object to the specified window.
	 * @param window - Instance of the game window
	 */
	void Scene::render(sf::RenderWindow& window) {

		// Render each entity
		for (auto& object : objects) {
			object->render(window);
		}

		// Set camera view
		window.setView(camera);
	}

	/**
	 * Add an object to the scene
	 * @param Object* - game object we want to add
	 */
	void Scene::add(Object* object) {

		// Addd gameObject to objects list
		objects.push_back (object);
	}

	/**
	 * Remove an object from the scene
	 * @param Object* - game object we want to add
	 */
	void Scene::remove(Object* object) {

	}

	/**
	 * Scene name getter
	 * @return string - scene name
	 */
	std::string Scene::getName() const {

		// Return current name
		return name;
	}

	/**
	 * Flush the scene instance
	 */
	void Scene::flush() {

	}
}
