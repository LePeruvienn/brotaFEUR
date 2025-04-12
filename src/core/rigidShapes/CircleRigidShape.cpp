#include "CircleRigidShape.h"

namespace Physics {

	/**
	 * CircleRigidShape Constructor
	 * @param x - rigidShape start X coordinate
	 * @param y - rigidShape start Y coordinate
	 * @param mass - rigidShape mass
	 * @param radius - rigidShape circle's radius
	 */
	CircleRigidShape::CircleRigidShape (float x, float y, float mass, float radius)
		// Use parent's constructor, and set radius
		: RigidShape(x, y, mass), radius(radius) {

		type = CIRCLE;
	};

	/**
	 * Updating current rigidShape
	 * @param deltaTime
	 */
	void CircleRigidShape::update (float deltaTime) {
		
		// Nothing to add yet
	}
	

	/**
	 * Check if RigidShape is colliding with an other
	 * @param rigidShape
	 */
	bool CircleRigidShape::isColliding (RigidShape& other) {

		return false;
	}

	/**
	 * Check if RigidShape is colliding with an Rectangle
	 * @param rigidShape
	 */
	bool CircleRigidShape::isCollidingWithRectangle(RigidShape& rectangle) {

		return false;
	}

	/**
	 * Check if RigidShape is colliding with a circle
	 * @param rigidShape
	 */
	bool CircleRigidShape::isCollidingWithCircle(RigidShape& circle) {

		return false;
	}
}
