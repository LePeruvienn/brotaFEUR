#ifndef CIRCLE_RIGIDSHAPE_H
#define CIRCLE_RIGIDSHAPE_H

#include "RigidShape.h"

namespace Physics {

	
	/**
	 * Represent an shape in the game which interacts with the game physics
	 * This is the class for a circle shape
	 */
	class CircleRigidShape : public RigidShape {
	public:

		float radius; ///< Circle radius

		/**
		 * CircleRigidShape Constructor
		 * @param x - rigidShape start X coordinate
		 * @param y - rigidShape start Y coordinate
		 * @param mass - rigidShape mass
		 * @param radius - rigidShape circle's radius
		 */
		CircleRigidShape (
			float x,
			float y,
			float mass,
			float radius
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

#endif // CIRCLE_RIGIDSHAPE_H
