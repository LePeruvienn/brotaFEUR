#ifndef CIRCLE_RIGIDSHAPE_H
#define CIRCLE_RIGIDSHAPE_H

#include "RigidShape.h"

namespace Physics {

	class CircleRigidShape : RigidShape {

		float radius; ///< Circle radius

		CircleRigidShape (
			float x,
			float y,
			float mass,
			float radius
		);

		void update(float deltaTime) override;
	};
}

#endif // CIRCLE_RIGIDSHAPE_H
