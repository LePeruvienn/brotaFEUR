#ifndef ANIMATION_H // Make the compiler include this once
#define ANIMATION_H

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

/** @module Render */
namespace Render {

	/**
	 * Class to create different animations
	 */
	class Animation {
	public:

		/**
		 * Animation class constructor
		 * @param texture - Texture source of the animation
		 * @param frameCount - Number of frame in the texture
		 * @param frameWidth - Width of a frame
		 * @param frameHeight - Height of a frame
		 * @param frameDuration - Time to wait between each frames
		 */
		Animation(
			sf::Texture& texture,
			int frameCount,
			float frameWidth,
			float frameHeight,
			float frameDuration
		);

		/**
		 * Update current animation
		 * @param deltaTime - time eleapsed between now and the last frame
		 */
		void update (float deltaTime);
	};
}

#endif // ANIMATION_H
