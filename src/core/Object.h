// Fore the compiler to include this once
#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace Game {

	class Object {
	public:

		int id = -1; ///< Object game unique ID. Is set when the entity is added to the game, is equel to -1 if not set
		sf::Vector2f pos = sf::Vector2f(0.f, 0.f); ///< Current object's position

		/**
		 * constructs a new game object with specified parameters.
		 * @param x - x axis position
		 * @param y - y axis position
		 */
		Object(
			float x = 0.f,
			float y = 0.f
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
		virtual void update(float deltaTime) = 0;

		/**
		 * Renders the object to the specified window.
		 * @param window - Instance of the game window
		 */
		virtual void render(sf::RenderWindow& window) = 0;
	};
}

#endif // OBJECT_H
