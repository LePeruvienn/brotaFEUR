#include <cmath>
#include "CircleRigidShape.h"
#include "RectangleRigidShape.h"

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
		: RigidShape(x, y, mass, 0.f), radius(radius) {

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
	 * Check if RigidShape is colliding with an Rectangle
	 * @param rigidShape
	 */
	bool CircleRigidShape::isColliding(RigidShape& other) {

		// Used the function linked to the shape
		switch (other.type) {

			case CIRCLE:
				return CircleRigidShape::isCollidingWithCircle(other);

			case RECTANGLE:
				return CircleRigidShape::isCollidingWithRectangle(other);

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
	bool CircleRigidShape::isCollidingWithRectangle(RigidShape& other) {

		// Cast other rigidShape has RectangleRigidShape
		RectangleRigidShape* rectangle = dynamic_cast<RectangleRigidShape*>(&other);

		// Get the closest point of the rectangle to the circle
		float closestX = fmax(rectangle->pos.x, fmin(pos.x, rectangle->pos.x + rectangle->width));
		float closestY = fmax(rectangle->pos.y, fmin(pos.y, rectangle->pos.y + rectangle->height));

		// Get distance
		float dx = closestX - pos.x;
		float dy = closestY - pos.y;

		float distance = dx * dx + dy * dy;
		
		return distance <= radius * radius;
	}

	/**
	 * Check if RigidShape is colliding with a circle
	 * @param rigidShape
	 */
	bool CircleRigidShape::isCollidingWithCircle(RigidShape& other) {

		// Cast other rigidShape has CircleRigidShape
		CircleRigidShape* circle = dynamic_cast<CircleRigidShape*>(&other);

		// Compute distance
		float dx = circle->pos.x - pos.x;
		float dy = circle->pos.y - pos.y;

		float distance = dx * dx + dy * dy;

		// Get total radius
		float radiusTotal = circle->radius + radius;
		
		// If there distance if <= of there total radius there are colliding
		return distance <= (radiusTotal * radiusTotal);
	}
}
