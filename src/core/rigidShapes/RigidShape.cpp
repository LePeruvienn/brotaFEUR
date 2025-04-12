#include "RigidShape.h"

namespace Physics {

	/**
	 * RigidShape Constructor
	 * @param x - rigidShape start X coordinate
	 * @param y - rigidShape start Y coordinate
	 * @param mass - rigidShape mass
	 */
	RigidShape::RigidShape(float x, float y, float mass, float angle) : 
		mass(mass), angle(angle) {
		
		pos = sf::Vector2f(x, y);
		velocity = sf::Vector2f(0.f, 0.f);
		acceleration = sf::Vector2f(0.f, 0.f);
	};

	void RigidShape::update (float deltaTime) {
	
		// Update pos depending on rigidShape's velocity
		pos.x += deltaTime * velocity.x;
		pos.y += deltaTime * velocity.y;
	}
}
