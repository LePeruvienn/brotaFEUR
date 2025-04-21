#include "Physics.h"
#include <iostream>

/**
 * Physics Namespace to handle all game's Physics
 */

/** @module Physics */
namespace Physics {

	int nextId = 0;
	std::vector<RigidShape*> objects; ///< Physics RigidShape list

	/**
	* Update current game's Physics
	* @param deltaTime
	*/
	void update(float deltaTime) {
	
		// Update all rigidShape logic
		for (auto& rigidShape : objects) { // Here we use auto cause rigidShape can be Circle, Rectangle ...
			rigidShape->update(deltaTime);
		}

		// std::cout << "Physics objects size : " << objects.size() << std::endl;
	}

	/**
	 * Add a RigidShape to the Physics objects array
	 * @param rigidShape
	 * @memberOf Physics
	 */
	void addObject(RigidShape* rigidShape) {

		// Set rigidShape's unique id
		rigidShape->id = nextId;

		// Increment nextId
		nextId++;
		
		// Add object  to Physics objects list
		objects.push_back(rigidShape);
	}

	/**
	 * Remove a RigidShape from the Physics objects array
	 * @param rigidShape
	 * @memberOf Physics
	 */
	void removeObject(RigidShape* rigidShape) {

		/* OPTIMIZE: We are looping into the physics array every time ...
		 * Maybe it will be better to add a logic similar to the game module ?
		 */

		// Serch the rigidShape in the objects array
		for (int i = 0; i < objects.size(); i++) {
			// If the two rigidShape have the same id
			if (objects[i]->id == rigidShape->id) {

				// Remove current rigidShape from the objects list
				objects.erase(objects.begin() + i);
			}
		}
	}
}
