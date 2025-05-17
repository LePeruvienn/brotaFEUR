#include "Scene.h"

/** @module Game */
namespace Game {

	Scene::Scene ()

	/**
	 * Scene update loop
	 * @param deltaTime
	 */
	void Scene::update(float deltaTime); ///< Update loop of current scene

	/**
	 * Renders the object to the specified window.
	 * @param window - Instance of the game window
	 */
	 void Scene::render(sf::RenderWindow& window);

	/**
	 * Add an object to the scene
	 * @param Object* - game object we want to add
	 */
	void Scene::add(Object* object);

	/**
	 * Remove an object from the scene
	 * @param Object* - game object we want to add
	 */
	void Scene::remove(Object* object);

	/**
	 * Flush the scene instance
	 */
	void Scene::flush();

	/**
	 * Camera setter
	 */
	void Scene::getCamera();

	/**
	 * Set current camera
	 * @param _camera - new camera to set
	 */
	void Scene::setCamera(Camera* _camera);
}
