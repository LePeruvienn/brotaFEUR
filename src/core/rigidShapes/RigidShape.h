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
		bool sensor = false; ///< Set current rigidShapes mode
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
		 * Updating current rigidShape
		 * @param deltaTime
		 */
		virtual void update(float deltaTime) = 0;

		/**
		 * Check if RigidShape is colliding with an other
		 * @param rigidShape
		 */
		virtual bool isColliding(RigidShape& other) = 0;

		/**
		 * Check if RigidShape is colliding with an Rectangle
		 * @param rigidShape
		 */
		virtual bool isCollidingWithRectangle(RigidShape& rectangle) = 0;

		/**
		 * Check if RigidShape is colliding with a circle
		 * @param rigidShape
		 */
		virtual bool isCollidingWithCircle(RigidShape& circle) = 0;
	};
}

#endif // RIGIDSHAPE_H
