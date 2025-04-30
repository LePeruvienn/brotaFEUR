#include "Animator.h"

namespace Render {

	/*
	 * Animator constructor
	 * @param vector<Animation*> - all current Animator animations pointers
	 */
	Animator::Animator(std::vector<Animation*> animations)
	// Set animations array
	: animations(animations) {

		// Create sprite object with currentAnimation texture (0 by default)
		sprite = new sf::Sprite(animations[currentIndex]->texture);

		// Player currentAnimation (0 by default)
		play(currentIndex);
	};

	/**
	 * Player animation on a sprite
	 * @param index - animation index to play
	 */
	void Animator::play(int index) {

		// Set new current index & animation
		currentIndex = index;
		currentAnimation = animations[index];

		// Reset timer & current frame
		timer = 0.f;
		currentFrame = 0;

		// Apply new texture to the sprite
		sprite->setTexture(currentAnimation->texture);

		// Set textureRect to currentFrame (the first one)
		sprite->setTextureRect(currentAnimation->frames[currentFrame]);

		// Set draw origin to sprite to the center of the animation frame
		sprite->setOrigin({
			currentAnimation->frameWidth / 2.f,
			currentAnimation->frameHeight / 2.f
		});
	};

	/**
	 * Update current animator
	 * @param deltaTime - time eleapsed between now and the last frame
	 */
	void Animator::update(float deltaTime) {

		// If frame duration has elapsed
		if (timer >= currentAnimation->frameDuration) {

			// Go to nextFrame
			currentFrame++;

			// Reset to zero if needed
			if (currentFrame == currentAnimation->frameCount)
				currentFrame = 0;

			// Set textureRect to next frame
			sprite->setTextureRect(currentAnimation->frames[currentFrame]);

			// Reset timer
			timer = 0.f;

			return;
		}

		// Add elapsed time
		timer += deltaTime;
	};

	/**
	 * Renders the animation to the specified window.
	 * @param window - Instance of the game window
	 */
	void Animator::render(sf::RenderWindow& window) {

		// Draw sprite
		window.draw(*sprite);
	}
}
