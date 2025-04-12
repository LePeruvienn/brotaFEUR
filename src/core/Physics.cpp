#include "Physics.h"

/**
 * Physics Namespace to handle all game's Physics
 */
namespace Physics {

	int nextId = 0;
	std::vector<RigidShape*> objects; ///< Physics RigidShape list

	/**
	* Update current game's Physics
	* @param deltaTime
	*/
	void update (float deltaTime) {
	
		// Update all rigidShape logic
		for (auto& rigidShape : objects) { // Here we use auto cause rigidShape can be Circle, Rectangle ...
			rigidShape->update(deltaTime);
		}
	}

	/**
	* Add an object to Physics objects list
	* @param rigidShape
	*/
	void addObject (RigidShape* rigidShape) {

		// Set rigidShape's unique id
		rigidShape->id = nextId;

		// Increment nextId
		nextId++;
		
		// Add object  to Physics objects list
		objects.push_back(rigidShape);
	}
}
