#include "CircleRigidShape.h"

namespace Physics {

	CircleRigidShape::CircleRigidShape (float x, float y, float mass, float radius) : 
		RigidShape(x, y, mass), radius(radius) {

		type = CIRCLE;
	};

	void CircleRigidShape::update (float deltaTime) {
		
		// Nothing to add yet
	}
}
