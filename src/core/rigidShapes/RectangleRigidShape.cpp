#include <math.h>
#include "RectangleRigidShape.h"
#include "CircleRigidShape.h"

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
		
		// Update rigidShape with parent's function
		RigidShape::update (deltaTime);
	}

	/**
	 * Check if RigidShape is colliding with an other
	 * @param rigidShape
	 */
	bool RectangleRigidShape::isColliding (RigidShape& other) {

		// Used the function linked to the shape
		switch (other.type) {

			case CIRCLE:
				return RectangleRigidShape::isCollidingWithCircle(other);

			case RECTANGLE:
				return RectangleRigidShape::isCollidingWithRectangle(other);

			// CAPSULE are not handled yet
			case CAPSULE:
				return false;
		}
		
		// Return false by default
		return false;
	}

	/**
	 * Check if RigidShape is colliding with an Rectangle
	 * @param rigidShape
	 */
	bool RectangleRigidShape::isCollidingWithRectangle(RigidShape& other) {

		// Cast other rigidShape has RectangleRigidShape
		RectangleRigidShape* rectangle = dynamic_cast<RectangleRigidShape*>(&other);

		return (pos.x < rectangle->pos.x + rectangle->width &&
				pos.x + width > rectangle->pos.x &&
				pos.y < rectangle->pos.y + rectangle->height &&
				pos.y + height > rectangle->pos.y);
	}

	/**
	 * Check if RigidShape is colliding with a circle
	 * @param rigidShape
	 */
	bool RectangleRigidShape::isCollidingWithCircle(RigidShape& other) {

		// Cast other rigidShape has CircleRigidShape
		CircleRigidShape* circle = dynamic_cast<CircleRigidShape*>(&other);

		// Get the closest point of the rectangle to the circle
		float closestX = fmax(pos.x, fmin(circle->pos.x, pos.x + width));
		float closestY = fmax(pos.y, fmin(circle->pos.y, pos.y + height));

		// Get distance
		float dx = closestX - circle->pos.x;
		float dy = closestY - circle->pos.y;

		float distance = dx * dx + dy * dy;
		
		return distance <= circle->radius * circle->radius;
	}
}
