#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <vector>
#include "../core/Object.h"
#include "../core/Physics.h"

namespace Projectile {

	class Projectile : public Game::Object {
	public:

		float speed; ///< Projectile speed
		sf::Vector2f direction; ///< Projectile direction
		float maxDuration; //< Max projectile duration before being deleted (in ms)
		
		sf::CircleShape shape; ///< Shape representing the projectile.
		Physics::RigidShape* rigidShape = nullptr; //< RigidShape linked to the projectile
	
		/**
		 * Projectile constructor
		 * @param x - x axis position
		 * @param y - y axis position
		 * @param dx - direction x where the projectile is going
		 * @param dy - direction y where the projectile is going
		 * @param speed - projectile speed
		 * @param maxDuration - time eleapsed before the projectile get deleted
		 * @param radius - projectile body radius
		 * @param color - projectile body color
		 */
		Projectile(
			float x = 50.f,
			float y = 50.f,
			float dx = 1.f,
			float dy = 1.f,
			float speed = 1.f,
			float maxDuration = 3000.f,
			float radius = 10.f,
			sf::Color color = sf::Color::Green
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

	private:

		float elapsedTime = 0; ///< Time eleapsed when created
	};

	/**
	 * Projectile constructor
	 * @param x - x axis position
	 * @param y - y axis position
	 * @param dx - direction x where the projectile is going
	 * @param dy - direction y where the projectile is going
	 * @param speed - projectile speed
	 * @param maxDuration - time eleapsed before the projectile get deleted
	 * @param radius - projectile body radius
	 * @param color - projectile body color
	 */
	Projectile* create (
		float x = 50.f,
		float y = 50.f,
		float dx = 1.f,
		float dy = 1.f,
		float speed = 1.f,
		float maxDuration = 3000.f,
		float radius = 10.f,
		sf::Color color = sf::Color::Yellow
	);
}

#endif // PROJECTILE_H
