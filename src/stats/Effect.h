// Fore the compiler to include this once
#ifndef EFFECT_H
#define EFFECT_H

#include "Stats.h"
#include "../entities/Entity.h"

namespace Entity {

	/**
	 * Class used to represent entities effects in the game.
	 * It's meant to be grant to an instance bonuses stats for a certain amount of duration
	 * The effects can be only appied to Entity instance of the game.
	 */
	class Effect {

	public:

		// WARNING: THE DURATION IS NOT WOKRING YET
		bool haveDuration = false; //< Did the Effect have a duration ?
		float duration = 0.f; ///< Total time in ms that the effect last on the entity
		Stats stats = Stats(); ///< Effects statitiscts applied to the entity
		

		/**
		 * Effects constructor class, initialize all stats start values
		 * @param health
		 * @param damage
		 * @param speed
		 */
		Effect ();

		void apply(Entity* entity) {

			// Adding the datats to the target
			entity->stats.damage += stats.damage;
			entity->stats.health += stats.health;
			entity->stats.speed += stats.speed;
		}
	};
}

#endif // EFFECT_H
