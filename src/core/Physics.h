#ifndef PHYSICS_H
#define PHYSICS_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "rigidShapes/RigidShape.h"

/**
 * Physics Namespace to handle all game's Physics
 * Is used as a module who has for goal to handle all game's physics
 */

/** @module Physics */
namespace Physics {

	extern int nextId; //< Next id to link to a rigidShape when added to the physics

	const float __GRAVITIY__ = 9.81f; ///< Gravity constant

	// Extern veut dire qu'on ne pas pas définir la liste ici mais dans un autre fichier (Physics.cpp)
	// => C'est obligatoire ici car sinon des qu'on va récupérer le fichier avec un #include "Physics.h"
	//    cela va redéfinir la liste "objects" et donc créer des érreur ! IL faut donc la décalder autres part
	extern std::vector<RigidShape*> objects; ///< Physics RigidShape list

	/**
	 * Update current Physics module
	 * @param deltaTime
	 * @memberOf Physics
	 */
	void update (float deltaTime);

	/**
	 * Add a RigidShape to the physics modules
	 * @param rigidShape
	 * @memberOf Physics
	 */
	void addObject (RigidShape* rigidShape);
}

#endif // GAME_H
