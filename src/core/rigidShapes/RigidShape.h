#ifndef RIGIDSHAPE_H
#define RIGIDSHAPE_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "RigidShapeTypes.h"
#include "../Object.h"

/** @module Physics */
namespace Physics {

	/**
	 * Represent an shape in the game which interacts with the game physics
	 * Usually linked to an entity to be used has his collider
	 */
	class RigidShape {
	public:
		
		int id = -1; //< rigidShape's unique id, if he inst added to the physics is equal to -1
		RigidShapeType type; //< What is the type of the current rigidShape (circle, rectangle, ect ...)
		sf::Vector2f pos; //< Current rigidShape position
		sf::Vector2f velocity; ///< Current rigidShape velocity
		sf::Vector2f acceleration; ///< Current rigidShape acceleration
		float mass = 1.f; ///< Current rigidShape mass
		float angle = 0.f; ///< Current rigidShape angle (in radian)
		bool sensor = false; ///< Set current rigidShapes mode
		std::vector<RigidShape*> collisions; ///< Current rigidShapes in collisions with the instance
		Game::Object* parent = nullptr; ///< RigidShape's parent

		/**
		 * RigidShape Constructor
		 * @param x - rigidShape start X coordinate
		 * @param y - rigidShape start Y coordinate
		 * @param mass - rigidShape mass
		 */
		RigidShape(float x, float y, float mass, float angle);

		/**
		 * RigidShape destructor
		 */
		virtual ~RigidShape() = default;

		/**
		 * Set rigidShape parent !
		 * @param Object*
		 */
		void setParent(Game::Object* object);


		/* TO KNOW => in CPP there is two types of virtual function :
		 * - classic virtual (without = 0) = this means that the function have a default value
		 *   that in declared in the parent cpp file
		 * - pure virtual (with = 0 !!) = that means that the function does NOT HAVE A DEFAULT VALUE !
		 *   so the functioin is not declared in in the parent's cpp file
		 */

		/**
		 * Updating current rigidShape
		 * @param deltaTime
		 */
		virtual void update(float deltaTime); // NOT PURE VIRTUAL (is declared in RigidShape.cpp)

		/**
		 * Check if RigidShape is colliding with an other
		 * @param rigidShape
		 */
		virtual bool isColliding(RigidShape& other) = 0; // PURE VIRUTAL (is not declared in RigidShape.cpp)

		/**
		 * Check if RigidShape is colliding with an Rectangle
		 * @param rigidShape
		 */
		virtual bool isCollidingWithRectangle(RigidShape& other) = 0;

		/**
		 * Check if RigidShape is colliding with a circle
		 * @param rigidShape
		 */
		virtual bool isCollidingWithCircle(RigidShape& other) = 0;
	};
}

#endif // RIGIDSHAPE_H
