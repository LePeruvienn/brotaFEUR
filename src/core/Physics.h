#ifndef PHYSICS_H
#define PHYSICS_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "rigidShapes/RigidShape.h"

/**
 * Physics Namespace to handle all game's Physics
 */
namespace Physics {

	const float __GRAVITIY__ = 9.81f; ///< Gravity constant

	std::vector<RigidShape*> objects; ///< Physics RigidShape list

	void update (float deltaTime);

	void addObject (RigidShape* rigidShape);
}

#endif // GAME_H
