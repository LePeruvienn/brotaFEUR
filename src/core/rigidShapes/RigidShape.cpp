#include "RigidShape.h"

namespace Physics {

	RigidShape::RigidShape (float x, float y, float mass) : 
		mass (mass) {
		
		pos = sf::Vector2f(x, y);
		velocity = sf::Vector2f(0.f, 0.f);
		acceleration = sf::Vector2f(0.f, 0.f);
	};

	void RigidShape::update (float deltaTime) {

	}

	bool RigidShape::isColliding (RigidShape& rigidShape) {

		return false;
	}
}
