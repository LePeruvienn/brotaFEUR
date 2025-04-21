#include "Bar.h"


namespace HUD {

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
	Bar::Bar(
		float x,
		float y,
		float width,
		float height,
		float startValue,
		float maxValue ,
		float minValue,
		sf::Color foregroundColor,
		sf::Color backgroundColor
	// Use parent's constructor
	) : Game::Object (x, y), 
	    width(width), height(height), minValue(minValue), maxValue(maxValue) {

		// Create gauge & background RectangleShape
		gauge = sf::RectangleShape({width, height});
		background = sf::RectangleShape({width, height});
		
		// Set rectangles colors
		gauge.setFillColor(foregroundColor);
		background.setFillColor(backgroundColor);

		/// Set bar position
		setPosition(x, y);

		// Set current value as startValue
		setValue(startValue);
	}

	/* Set the value of the bar
	 * @param value - new bar value
	 */
	void Bar::setValue(float newValue) {

		// Return if the value is unchanged
		if (newValue == value) return;

		// Set value between minValue & maxValue
		value = std::max(std::min(newValue, maxValue), minValue);

		// If current value must be updated
		if (value != oldValue)
			updateVisual();

		// Reset oldValue
		oldValue = value;
	}

	/* Get the current bar value
	 * @return current bar value
	 */
	float Bar::getValue() {

		return value;
	}

	/* Set the position of the bar
	 * @param x - new x coordinates
	 * @param y - new y coordinates
	 */
	void Bar::setPosition(float x, float y) {
		
		// Set rectangles positions
		gauge.setPosition({x, y});
		background.setPosition({x, y});
		
		// Use parent's function
		Game::Object::setPosition(x, y);
	}


	/**
	 * Update bar visual
	 */
	void Bar::updateVisual() {

		// Compute new width
		float newWidth = value / (maxValue - minValue) * width;

		// Set guage new width
		gauge.setSize({newWidth, height});
	}

	/**
	 * Callback function called before the entity is deleted
	 */
	void Bar::onDestroy() {

		// Use parent's function
		Game::Object::onDestroy();
	}

	/**
	 * Updates the object's logic.
	 * @param deltaTime - The time elapsed since the last frame (in ms)
	 */
	void Bar::update(float deltaTime) {


		// Use parent's update function !
		Game::Object::update(deltaTime);
	}

	/**
	 * Renders the object to the specified window.
	 * @param window - Instance of the game window
	 */
	void Bar::render(sf::RenderWindow& window) {

		// User parent's render function
		Game::Object::render(window);
	
		// Get current pos
		float x = pos.x;
		float y = pos.y;

		// If we have a parent we must adjust the position toward parent's pos
		if (parent != nullptr) {
		
			x += parent->pos.x;
			y += parent->pos.y;
		}

		// Set shape to bonus rigidShape current position
		background.setPosition({x, y});
		gauge.setPosition({x, y});

		// Draw first background and then gauge to keep it in front of the background
		window.draw(background);
		window.draw(gauge);
	}
}
