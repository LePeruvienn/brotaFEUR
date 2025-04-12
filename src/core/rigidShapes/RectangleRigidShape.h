#ifndef RECTANGLE_RIGIDSHAPE_H
#define RECTANGLE_RIGIDSHAPE_H

#include "RigidShape.h"

namespace Physics {

	
	/**
	 * Represent an shape in the game which interacts with the game physics
	 * This is the class for a rectangle shape
	 */
	class RectangleRigidShape : public RigidShape {
	public:

		float width; ///< Rectangle width
		float height; ///< Rectangle height

		/**
		 * RectangleRigidShape Constructor
		 * @param x      - rigidShape start X coordinate
		 * @param y      - rigidShape start Y coordinate
		 * @param mass   - rigidShape mass
		 * @param width  - rigidShape rectangle's width
		 * @param height - rigidShape rectangle's height
		 * @param angle  - rigidShape angle
		 */
		RectangleRigidShape (
			float x,
			float y,
			float mass,
			float width,
			float height,
			float angle
		);

		/**
		 * Updating current rigidShape
		 * @param deltaTime
		 */
		void update(float deltaTime) override;

		/**
		 * Check if RigidShape is colliding with an other
		 * @param rigidShape
		 */
		bool isColliding(RigidShape& other) override;

		/**
		 * Check if RigidShape is colliding with an Rectangle
		 * @param rigidShape
		 */
		bool isCollidingWithRectangle(RigidShape& other) override;

		/**
		 * Check if RigidShape is colliding with a circle
		 * @param rigidShape
		 */
		bool isCollidingWithCircle(RigidShape& other) override;
	};
}

#endif // RECTANGLE_RIGIDSHAPE_H
