#include "Physics.h"

/**
 * Physics Namespace to handle all game's Physics
 */
namespace Physics {

	/**
	* Update current game's Physics
	* @param deltaTime
	*/
	void update (float deltaTime) {
	
		// Update all rigidShape logic
		for (auto& rigidShape : objects) {
			rigidShape->update(deltaTime);
		}
	}

	/**
	* Add an object to Physics objects list
	* @param rigidShape
	*/
	void addObject (RigidShape* rigidShape) {
		
		// Add object  to Physics objects list
		objects.push_back(rigidShape);
	}
}
