#include "Utils.h"

/** @module Utils */
namespace Utils {

	/**
	 * Nameplace use to add classic static function that are quiet usefull
	 * @param value - value that we want to update
	 * @param target - target we want to reach
	 * @param lerp - how smooth/fast we must reach the target
	 * @return float
	 */
	float lerp(float value, float target, float lerp) {
		// return lerped value
        return value + lerp * (target - value);
	}
}
