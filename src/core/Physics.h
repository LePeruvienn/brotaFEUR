#ifndef PHYSICS_H
#define PHYSICS_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

/**
 * Physics Namespace to handle all game's Physics
 */
namespace Physics {

	const float __GRAVITIY__ = 9.81f; ///< Gravity constant

	/**
	 * Represent an shape in the game which interacts with the game physics
	 * Usually linked to an entity to be used has his collider
	 */
	class RigidShape {
	public:

		/**
		 * RigidShape Constructor
		 * @param x - rigidShape start X coordinate
		 * @param y - rigidShape start Y coordinate
		 * @param mass - rigidShape mass
		 */
		RigidShape(float x, float y, float mass);
		~RigidShape();

		sf::Vector2f pos;
		sf::Vector2f velocity;
		sf::Vector2f acceleration;
		float mass = 1.f;

		void update(float deltaTime);

		bool isColliding(RigidShape& rigidShape);
	};

	extern std::vector<RigidShape*> objects; ///< Physics RigidShape list
}

#endif // GAME_H
