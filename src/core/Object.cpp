#include "Object.h"
#include <iostream>

namespace Game {

	Object::Object (float x, float y) {

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

		// Call on destroy callback (can be managed with override)
		onDestroy();

		//delete this; // CAUTION WITH THIS IT CAN DO SOME PRETTY BAD THINGS
	};

	/**
	 * toBeDeleted getter
	 */
	bool Object::getToBeDeleted() {
		// return private
		return toBeDeleted ;
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
	 * Callback function called before entity is destroyed
	 */
	void Object::onDestroy () {

		// Nothing to do yet 😢
	}
}
