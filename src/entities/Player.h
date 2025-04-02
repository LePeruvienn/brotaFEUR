
#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

/**
 * Player entity who will be controlled by a player
 * Chlid class from the Entity class
 */
class Player : public Entity {
public:

	/**
	 * constructs a new entity object with specified parameters.
	 * @param x - x axis position
	 * @param y - y axis position
	 * @param radius - entity body radius
	 * @param color - entity body color
	 */
	Player(float x, float y, float radius = 30.f, sf::Color color = sf::Color::Blue);

	/**
	 * Updates the player's logic.
	 * @param deltaTime - The time elapsed since the last frame
	 */
	void update(sf::Time deltaTime) override;

	/**
	 * Renders the player to the specified window.
	 * @param window - Instance of the game window
	 */
	// void render(sf::RenderWindow& window) override;
};

#endif // PLAYER_H
