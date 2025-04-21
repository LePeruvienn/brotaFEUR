// Fore the compiler to include this once
#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

/** @module Game */
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
		 * Mark Function !
		 * Mark & Sweep method: This function mark the current object to be after deleted by the game logic
		 */
		void destroy();

		/**
		 * Sweep Function !
		 * Mark & Sweep method: This function sweep the objec to to game logic & memory
		 */
		void _destroy();

		/**
		 * toBeDeleted getter
		 */
		bool getToBeDeleted();

		/* Set the position of the object
		 * @param x - new x coordinates
		 * @param y - new y coordinates
		 */
		virtual void setPosition(float x, float y);

		/**
		 * Callback function called before the object is deleted
		 */
		virtual void onDestroy();

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

	private:
		
		bool toBeDeleted = false; ///< When is true the game logic will delete the object instance
	};
}

#endif // OBJECT_H
