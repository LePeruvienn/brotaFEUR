#include "Stats.h"

namespace Entity {

	/**
	 * Stats constructor class, initialize all stats start values
	 * @param health
	 * @param damage
	 * @param speed
	 */
	Stats::Stats(int health, int damage, float speed)
		// Setting stats values
		: health(health), damage(damage), speed(speed) {

		// Nothing to do more
	};


	/**
	 * Used to make an entity take damage from an ather entity
	 * @param amount - Damage amount we are taking
	 * @return isDead - return true if entity is dead, false either
	 */
	bool Stats::takeDamage (int amount) {

		return false;
	}

	/**
	 * Used to heal an entity
	 * @param amount - Heal amount
	 */
	void Stats::heal (int amount) {

	}
}
