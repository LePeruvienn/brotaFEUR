#include "RectangleRigidShape.h"

namespace Physics {

	/**
	 * RectangleRigidShape Constructor
	 * @param x - rigidShape start X coordinate
	 * @param y - rigidShape start Y coordinate
	 * @param mass - rigidShape mass
	 * @param radius - rigidShape rectangle's radius
	 */
	RectangleRigidShape::RectangleRigidShape (float x, float y, float mass, float width, float height, float angle)
		// Use parent's constructor, and set radius
		: RigidShape(x, y, mass, angle), width(width), height(height) {

		type = RECTANGLE;
	};

	/**
	 * Updating current rigidShape
	 * @param deltaTime
	 */
	void RectangleRigidShape::update (float deltaTime) {
		
		// Nothing to add yet
	}
	

	/**
	 * Check if RigidShape is colliding with an other
	 * @param rigidShape
	 */
	bool RectangleRigidShape::isColliding (RigidShape& other) {

		return false;
	}

	/**
	 * Check if RigidShape is colliding with an Rectangle
	 * @param rigidShape
	 */
	bool RectangleRigidShape::isCollidingWithRectangle(RigidShape& rectangle) {

		return false;
	}

	/**
	 * Check if RigidShape is colliding with a circle
	 * @param rigidShape
	 */
	bool RectangleRigidShape::isCollidingWithCircle(RigidShape& circle) {

		return false;
	}
}
