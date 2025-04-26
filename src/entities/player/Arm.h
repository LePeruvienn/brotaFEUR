// Force compiler to include this once
#ifndef ARM_H
#define ARM_H

#include "../mob/Mob.h"
#include "../../core/Object.h"
#include "../../data/items/Weapon.h"

namespace Player {

	class Arm : public Game::Object {
	public:

		bool isEmpty = true; ///< Is the hand have an equipped weapon
		// Not using this yet
		// Data::Weapon* currentWeapon; //< Pointer of the current wepaon used data

		/**
		 * Arm class constructor
		 * @param x - start X coordinates
		 * @param y - start Y coordinates
		 * @param size - Arm size
		 */
		Arm(float x = 0.f, float y = 0.f, float size = 10.f);

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

		sf::RectangleShape shape; ///< Current weapon size
		float size = 10.f; ///< Arm size

		float shootCoolown = 400.f; ///< Time before the arm shoot an other projectile
		float shotTimer = 0.f; ///< Time elapsed after the arm shot his last projectile
	
		/**
		 * Make the arm rotate towards the mob in parameter
		 * @param Mob* - mob target we want to rotate to
		 */
		void rotateTowardsMob(Mob::Mob* mob);

		/**
		 * Make the arm shoot a target mob
		 * @param deltaTime - The time elapsed since the last frame (in ms)
		 * @param Mob* - mob target we want to rotate to
		 */
		void handleShoot(float deltaTime, Mob::Mob* mob);
	};
}

#endif // ARM_H
