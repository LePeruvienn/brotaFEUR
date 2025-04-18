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
		bool haveDuration; //< Did the Effect have a duration ?
		float duration; ///< Total time in ms that the effect last on the entity
		Stats stats; ///< Effects statitiscts applied to the entity
		

		/**
		 * effects constructor class, initialize all stats start values
		 * @param health
		 * @param damage
		 * @param speed
		 */
		Effect (
			bool haveDuration = false,
			float duration = 0.f,
			Stats stats = Stats(0, 0, 0.2f)
		);

		/**
		 * Effects constructor class, initialize all stats start values
		 * @param health
		 * @param damage
		 * @param speed
		 */
		void apply(Entity* entity);
	};
}

#endif // EFFECT_H
