// Fore the compiler to include this once
#ifndef STATS_H
#define STATS_H

/** @module Entity */
namespace Entity {

	/**
	 * Class used to represent entities statistics in the game.
	 * Only used with entities instances.
	 * IS nice to store all stats linked functions.
	 */
	class Stats {

	public:

		int health; ///< Health
		int damage; ///< Damage
		float speed; ///< Speed

		/**
		 * Stats constructor class, initialize all stats start values
		 * @param health
		 * @param damage
		 * @param speed
		 */
		Stats (
			int health = 100,
			int damage = 5,
			float speed = 0.2f
		);

		/**
		 * Used to make an entity take damage from an ather entity
		 * @param amount - Damage amount we are taking
		 * @return isDead - return true if entity is dead, false either
		 */
		bool takeDamage (int amount);

		/**
		 * Used to heal an entity
		 * @param amount - Heal amount
		 */
		void heal (int amount);
	};
}

#endif // STATS_H
