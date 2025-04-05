#include "Mob.h"

/**
 * constructs a new entity object with specified parameters.
 * @param x - x axis position
 * @param y - y axis position
 * @param radius - entity body radius
 * @param color - entity body color
 */
Mob::Mob(float x, float y, float radius, sf::Color color, Stats stats) 
	// Use parent's base contructor
	: Entity(x, y, radius, color, stats) {

	// Nothing to do more !
}

/**
 * Updates the player's logic.
 * @param deltaTime - The time elapsed since the last frame
 */
void Mob::update(float deltaTime) {

	// Use Entity update
	Entity::update (deltaTime);
}

/**
 * Renders the entity to the specified window.
 * @param window - Instance of the game window
 */
void Mob::render(sf::RenderWindow& window) {
	
	// Use Entity render
	Entity::render(window);
}
