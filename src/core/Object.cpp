#include "Game.h"
#include "Object.h"
#include <iostream>

namespace Game {

	Object::Object (float x, float y) {

		// Set game object ID
		id = Game::nextId;

		// Increment nextId
		Game::nextId++;

		// Set object position
		pos.x = x;
		pos.y = y;
	}

	/**
	 * Destroy current Object
	 * Mark & Sweep method: This function mark the current object to be after deleted by the game logic
	 */
	void Object::destroy () {

		// std::cout << "Object : toBeDeleted = true" << std::endl;

		// Set to be deleted to true
		toBeDeleted = true;
	}


	/**
	 * Private destory function, used to delete the object from game logic & memory
	 */
	void Object::_destroy() {

		// std::cout << "Object : onDestroy()" << std::endl;
	
		// If we have childrens we delte them before
		for (int i = 0; i < objects.size(); i++)
			objects[i]->_destroy();

		// If we have a parent remove us from parent's objects list
		if (parent != nullptr)
			parent->remove(this);

		// Call on destroy callback (can be managed with override)
		onDestroy();

		// Delte object from memory
		delete this; // CAUTION WITH THIS IT CAN DO SOME PRETTY BAD THINGS
	};

	/**
	 * toBeDeleted getter
	 */
	bool Object::getToBeDeleted() {
		// return private
		return toBeDeleted ;
	}

	/**
	 * Set current object's parent
	 */
	void Object::setParent(Object* object) {

		// If we already have a parent remove us from parent
		if (parent != nullptr)
			parent->remove(this);

		// Set object's new parent
		parent = object;
	}

	/**
	 * Add the object in param has a children of current object !
	 * DO NOT add an object at two parent's !
	 * @param Object* - The object we want to set has a child
	 */
	void Object::add(Object* object) {
		
		// If the object has already a parent remove it from parent
		if (object->parent != nullptr)
			object->parent->remove(object);

		// Add the object to the childrens list
		objects.push_back(object);
		
		// Set objects's parent
		object->setParent(this);
	}

	/**
	 * Remove a children for the current objects
	 * (it only remove it from the objects list)
	 * @param Object* - The object we want to remove
	 */
	void Object::remove(Object* object) {

		// Search in the childrens array
		for (int i = 0; i < objects.size(); i++) {
			// If the current children have the same id of the object
			if (objects[i]->id == object->id) {
				// Remove it from the list
				objects.erase(objects.begin() + i);
			}
		}
	}

	/* Set the position of the object
	 * @param x - new x coordinates
	 * @param y - new y coordinates
	 */
	void Object::setPosition(float x, float y) {

		// Set object nex position
		pos.x = x;
		pos.y = y;
	}

	/**
	 * Get object position in the current scene,
	 * Used to parse childrens object pos to current real world pos
	 */
	sf::Vector2f Object::getRawPos() {

		// if there is no parent return pos
		if (parent == nullptr) return pos;

		// Get parent raw pos
		sf::Vector2f parentPos = parent->getRawPos();
	
		// Return computed raw pos
		return {
			pos.x + parentPos.x,
			pos.y + parentPos.y
		};
	}

	/**
	 * Updates the object's logichis
	 * This function must be called first before children class update !
	 * @param deltaTime - The time elapsed since the last frame (in ms)
	 */
	void Object::update(float deltaTime) {

		// Update all the childrens objects !
		for (int i = 0; i < objects.size(); i++)
			objects[i]->update(deltaTime);
	}

	/**
	 * Renders the object to the specified window.
	 * This function must be called first before children class render !
	 * @param window - Instance of the game window
	 */
	void Object::render(sf::RenderWindow& window) {

		// Render all the childrens objects !
		for (int i = 0; i < objects.size(); i++)
			objects[i]->render(window);
	}

	/**
	 * Callback function called before entity is destroyed
	 */
	void Object::onDestroy () {

		// Nothing to do yet 😢
	}
}
