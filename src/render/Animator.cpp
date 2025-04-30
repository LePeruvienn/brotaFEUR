#include "Animator.h"

namespace Render {

	/**
	 * Animator constructor
	 * @param sprite - Sprite whos we are gonna apply an animation
	 */
	Animator::Animator(sf::Sprite* sprite) : sprite(sprite) {

		// Nothing to do here
	};

	/**
	 * Player animation on a sprite
	 * @param deltaTime - time eleapsed between now and the last frame
	 */
	void Animator::play(Animation* animation) {
	
		// If animation is already set dont change it
		if (currentAnimation == animation) return;
	
		// Set new current animation
		currentAnimation = animation;

		// Aply new animation texture to sprite
		currentAnimation->applyTexture(*sprite);
	};

	/**
	 * Update current animator
	 * @param deltaTime - time eleapsed between now and the last frame
	 */
	void Animator::update(float deltaTime) {

		// If there is no animation or sprite to update we do nothing
		if (currentAnimation == nullptr || sprite == nullptr) return;

		// Update animation
		currentAnimation->update(deltaTime, *sprite);
	};
}
