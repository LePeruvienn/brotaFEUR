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
		sf::Texture texture; ///< Reference to texture
		int frameCount; ///< Number of frames in the animation
		int frameWidth; ///< Frame width
		int frameHeight; ///< Frame height
		float frameDuration; ///< Time to wait between each frame
		std::vector<sf::IntRect> frames; ///< All frame rectangles
		
		/*
		 * Structure contustructor
		 */
		Animation(
			std::string name,
			sf::Texture texture,
			int frameCount,
			int frameWidth,
			int frameHeight,
			float frameDuration)
		// Set values
		: name(name),
		  texture(texture),
		  frameCount(frameCount),
		  frameWidth(frameWidth),
		  frameHeight(frameHeight),
		  frameDuration(frameDuration)
		{
			// Pre-allocate memory to avoid reallocations
			frames.reserve(frameCount);
			// Store the IntRect datas in the frames array
			for (int i = 0; i < frameCount; i++)
				// Use `emplace_back` so we dont have to create a new object !
				frames.emplace_back(sf::IntRect({i * frameWidth, 0}, {frameWidth, frameHeight}));
		}
	};
}

#endif // ANIMATION_H
