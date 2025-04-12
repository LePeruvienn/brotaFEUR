#include "RigidShape.h"

namespace Physics {

	/**
	 * RigidShape Constructor
	 * @param x - rigidShape start X coordinate
	 * @param y - rigidShape start Y coordinate
	 * @param mass - rigidShape mass
	 */
	RigidShape::RigidShape (float x, float y, float mass) : 
		mass (mass) {
		
		pos = sf::Vector2f(x, y);
		velocity = sf::Vector2f(0.f, 0.f);
		acceleration = sf::Vector2f(0.f, 0.f);
	};
}
