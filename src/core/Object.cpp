#include "Object.h"
#include "Physics.h"
#include "rigidShapes/CircleRigidShape.h"

namespace Game {

	Object::Object (float x, float y, float radius, sf::Color color)
		// Intialize class values
		: shape(radius) {

		// Set shape position & color
		shape.setPosition({x, y});
		shape.setFillColor(color);

		// Create entity rigidShape
		rigidShape = new Physics::CircleRigidShape (x, y, 1.f, radius);

		// Add the rigidShape to the Physics
		Physics::addObject (rigidShape);
	}

	/**
	 * Updates the object's logic.
	 * @param deltaTime - The time elapsed since the last frame (in ms)
	 */
	void Object::update(float deltaTime) {

	}

	/**
	 * Renders the object to the specified window.
	 * @param window - Instance of the game window
	 */
	void Object::render(sf::RenderWindow& window) {

		// Set shape to player rigidShape current position
		shape.setPosition(rigidShape->pos);

		// Draw shape into the screen
		window.draw(shape);
	}
}
