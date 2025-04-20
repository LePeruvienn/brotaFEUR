#ifndef UTILS_H
#define UTILS_H

/**
 * Namespace use to add classic static function that are quiet usefull
 * So it's nice to set them here
 */

/** @module Utils */
namespace Utils {

	/**
	 * Nameplace use to add classic static function that are quiet usefull
	 * @param value - value that we want to update
	 * @param target - target we want to reach
	 * @param lerp - how smooth/fast we must reach the target
	 * @return float
	 */
	float lerp(float value, float target, float lerp);
}

#endif // UTILS_H

