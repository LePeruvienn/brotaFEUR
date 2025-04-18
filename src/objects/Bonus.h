#ifndef BONUS_H
#define BONUS_H
#include <vector>
#include "../core/Object.h"
#include "../stats/Effect.h"

namespace Bonus {

	/**
	 * Classed used to represent the bonuses of the game.
	 * When a Entity is interacting with them they are being granted of the bonus effect
	 */
	class Bonus : public Game::Object {
	public:

		Entity::Effect effect; ///< Bonus's effect
	
		sf::CircleShape shape; ///< Shape representing the bonus.
		Physics::RigidShape* rigidShape = nullptr; //< RigidShape linked to the bonus

		/**
		 * Bonus constructor
		 * @param x - x axis position
		 * @param y - y axis position
		 * @param radius - entity body radius
		 * @param color - entity body color
		 */
		Bonus(
			float x = 50.f,
			float y = 50.f,
			float radius = 30.f,
			sf::Color color = sf::Color::Magenta,
			Entity::Effect effect = Entity::Effect()
		);

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
	};

	extern std::vector<Bonus*> objects; ///< list of all the bonuses objects in the game
	
	/**
	 * Add a bonus to the bonuses list
	 * @param Bonus*
	 */
	void add (Bonus* bonus);

	/**
	 * Create a new Bonus object instance, and add it to the game logic
	 * @param x - x axis position
	 * @param y - y axis position
	 * @param radius - entity body radius
	 * @param color - entity body color
	 * @return Bonus*
	 */
	Bonus* create(
		float x = 50.f,
		float y = 50.f,
		float radius = 30.f,
		sf::Color color = sf::Color::Magenta,
		Entity::Effect effect = Entity::Effect()
	);
}

#endif // BONUS_H
