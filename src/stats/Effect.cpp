#include "Effect.h"

/** @module Entity */
namespace Entity {

	/**
	 * effects constructor class, initialize all stats start values
	 * @param health
	 * @param damage
	 * @param speed
	 */
	Effect::Effect (bool haveDuration, float duration, Stats stats)
		: haveDuration(haveDuration), duration(duration), stats(stats) {

	};

	/**
	 * Effects constructor class, initialize all stats start values
	 * @param health
	 * @param damage
	 * @param speed
	 */
	void Effect::apply (Entity* entity) {

		// Adding the datats to the target
		entity->stats.damage += stats.damage;
		entity->stats.health += stats.health;
		entity->stats.speed += stats.speed;
	};

}
