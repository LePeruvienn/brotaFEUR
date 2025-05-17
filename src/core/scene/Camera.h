#include <vector>
#include "../Object.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

/** @module Game */
namespace Game {

	class Camera {
	public:
		
		/**
		 * Set new camera position
		 * @param x
		 * @param y
		 */
		void setPosition(float x, float y);

		/**
		 * Set Camera zoom
		 * @param value - new camera zoom value
		 */
		void setZoom (float value);

	private:

		sf::Vector2f pos = sf::Vector2f(0.f, 0.f); ///< Current camera's position

		float width = 800.f; ///< Camera current width
		float height = 600.f; ///< Camera current height
	
		float zoom = 1.f; ///< Current camera zoom
	};
}
