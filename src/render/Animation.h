#ifndef ANIMATION_H // Make the compiler include this once
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <string>

/** @module Render */
namespace Render {

	/*
	 * Animation Structure !
	 * Used to store animation datas an use them multiple animators
	 */
	struct Animation {

		std::string name; ///< Name of the animation
		sf::Texture& texture; ///< Reference to texture
		int frameCount; ///< Number of frames in the animation
		int frameWidth; ///< Frame width
		int frameHeight; ///< Frame height
		float frameDuration; ///< Time to wait between each frame
		
		/*
		 * Structure contustructor
		 */
		Animation(
			std::string name,
			sf::Texture& texture,
			int frameCount,
			int frameWidth,
			int frameHeight,
			float frameDuration)
		// Set values
		: name(name),
		  texture(texture),
		  frameWidth(frameWidth),
		  frameHeight(frameHeight),
		  frameDuration(frameDuration)
		{}
	};
}

#endif // ANIMATION_H
