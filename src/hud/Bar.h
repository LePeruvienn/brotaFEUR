#ifndef BAR_H
#define BAR_H

#include "../core/Object.h"

namespace HUD {

	class Bar : public Game::Object {
	public:

		/* Bar constructor
		 * @param x - start x position
		 * @param y - start y position
		 * @param width - bar width
		 * @param height - bar height
		 * @param startValue - bart start value
		 * @param maxValue - max value that the bar can have
		 * @param minValue - min value that the bar can have
		 * @param foregroundColor - color representing the current value
		 * @param backgroundColor - color representing the empty space (Transparent by default)
		 */
		Bar(
			float x = 0.f,
			float y = 0.f,
			float width = 100.f,
			float height = 20.f,
			float startValue = 100.f,
			float maxValue = 100.f,
			float minValue = 0.f,
			sf::Color foregroundColor = sf::Color::Red,
			sf::Color backgroundColor = sf::Color::Transparent
		);

		/* Set the value of the bar
		 * @param value - new bar value
		 */
		void setValue(float value);

		/* Get the current bar value
		 * @return current bar value
		 */
		float getValue();


		/* Set the position of the bar
		 * @param x - new x coordinates
		 * @param y - new y coordinates
		 */
		void setPosition(float x, float y) override;

		/**
		 * Updates the object's logic.
		 * @param deltaTime - The time elapsed since the last frame (in ms)
		 */
		void update(float deltaTime) override;

		/**
		 * Callback function called before the entity is deleted
		 */
		void onDestroy() override;

		/**
		 * Renders the object to the specified window.
		 * @param window - Instance of the game window
		 */
		void render(sf::RenderWindow& window) override;

	
	private:

		float width; ///< gauge width
		float height; ///< gauge height

		float value; ///< Current gauge value
		float oldValue; //< Old Gauge value

		float maxValue = 100.f; ///< Max gauge value
		float minValue = 0.f; ///< Min gauge value

		sf::RectangleShape gauge; ///< Shape representing the gauge
		sf::RectangleShape background; ///< Shape representing the gauge background

		/**
		 * Update bar visual
		 */
		void updateVisual();
	};
}

#endif // BAR_H
