#ifndef RIGIDSHAPE_H
#define RIGIDSHAPE_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "RigidShapeTypes.h"

namespace Physics {

	/**
	 * Represent an shape in the game which interacts with the game physics
	 * Usually linked to an entity to be used has his collider
	 */
	class RigidShape {
	public:

		RigidShapeType type; //< What is the type of the current rigidShape (circle, rectangle, ect ...)
		sf::Vector2f pos; //< Current rigidShape position
		sf::Vector2f velocity; ///< Current rigidShape velocity
		sf::Vector2f acceleration; ///< Current rigidShape acceleration
		float mass = 1.f; ///< Current rigidShape mass
		std::vector<RigidShape*> collisions; ///< Current rigidShapes in collisions with the instance
		/**
		 * RigidShape Constructor
		 * @param x - rigidShape start X coordinate
		 * @param y - rigidShape start Y coordinate
		 * @param mass - rigidShape mass
		 */
		RigidShape(float x, float y, float mass);

		/**
		 * RigidShape destructor
		 */
		virtual ~RigidShape() = default;

		/**
		 * Updating
		 * @param deltaTime
		 */
		virtual void update(float deltaTime);

		/**
		 * Updating
		 * @param deltaTime
		 */
		virtual bool isColliding(RigidShape& rigidShape);
	};
}

#endif // RIGIDSHAPE_H
