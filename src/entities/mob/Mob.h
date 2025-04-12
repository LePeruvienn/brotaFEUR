#ifndef MOB_H
#define MOB_H

#include "../Entity.h"

/**
 * Mob entity who will be controlled by a mob
 * Chlid class from the Entity class
 */
class Mob : public Entity {
public:

	/**
	 * constructs a new entity object with specified parameters.
	 * @param x - x axis position
	 * @param y - y axis position
	 * @param radius - entity body radius
	 * @param color - entity body color
	 */
	Mob(
		float x,
		float y,
		float radius = 30.f,
		sf::Color color = sf::Color::Red,
		Stats stats = Stats()
	);

	/**
	 * Updates the mob's logic.
	 * @param deltaTime - The time elapsed since the last frame (in ms)
	 */
	void update(float deltaTime) override;

	/**
	 * Renders the mob to the specified window.
	 * @param window - Instance of the game window
	 */
	void render(sf::RenderWindow& window) override;
};

#endif // MOB_H
