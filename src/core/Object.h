// Fore the compiler to include this once
#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "rigidShapes/RigidShape.h"

namespace Game {

	class Object {
	public:

		int id = -1; ///< Object game unique ID. Is set when the entity is added to the game, is equel to -1 if not set
		sf::CircleShape shape; ///< Shape representing the object.
		Physics::RigidShape* rigidShape = nullptr; //< RigidShape linked to the object

		/**
		 * constructs a new game object with specified parameters.
		 * @param x - x axis position
		 * @param y - y axis position
		 * @param radius - entity body radius
		 * @param color - entity body color
		 */
		Object(
			float x = 0.f,
			float y = 0.f,
			float radius = 30.f,
			sf::Color color = sf::Color::White
		);

		/**
		 * Virtual destructor for the Object class.
		 * This ensures that derived classes' destructors are called properly
		 */
		virtual ~Object() = default;

		/**
		 * Updates the object's logic.
		 * @param deltaTime - The time elapsed since the last frame (in ms)
		 */
		virtual void update(float deltaTime);

		/**
		 * Renders the object to the specified window.
		 * @param window - Instance of the game window
		 */
		virtual void render(sf::RenderWindow& window);
	};
}

#endif // OBJECT_H
