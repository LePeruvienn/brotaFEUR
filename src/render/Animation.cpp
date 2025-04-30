#include "Animation.h"

namespace Render {

	/**
	 * Animation class constructor
	 * @param texture - Texture source of the animation
	 * @param frameCount - Number of frame in the texture
	 * @param frameWidth - Width of a frame
	 * @param frameHeight - Height of a frame
	 * @param frameDuration - Time to wait between each frames (in ms)
	 */
	Animation::Animation(
		std::string src,
		int frameCount,
		float frameDuration
	// Set properties values
	) : texture(src), frameCount(frameCount), frameDuration(frameDuration){

		// Get texture size
		sf::Vector2u size = texture.getSize();

		// Compute height & width
		float width = size.x / frameCount;
		float height = size.y;

		// Compute frames array
		for (int i = 0; i < frameCount; i++) {

			// Create current frame boundaries
			sf::IntRect rect = sf::IntRect(
				{i * width, 0}, // Pos (cooridnates x & y)
				{height, height} // Size (width & height)
			);

			// Add it to frames array
			frames.push_back(rect);
		}
	};


	/**
	 * Update current animation
	 * @param deltaTime - time eleapsed between now and the last frame
	 */
	void Animation::update (float deltaTime, sf::Sprite& sprite) {

		// If we dont reach the end of the frame duration, we just update time
		if (frameTime < frameDuration) {

			// Add elapsed to frameTime
			frameTime += deltaTime;

			// Stop here
			return;
		}

		// If we have reached the end of the frame duration, go to next frame
		if (currentFrame < frameCount)
			currentFrame++;
		// If we are at the last frame reset it to zero
		else
			currentFrame = 0;
			
		// Set set current texture to next frame place
		sprite.setTextureRect(frames[currentFrame]);
	};

	/**
	 * Update current animation
	 * @param sprite& - reference of the sprite we want to apply the texture
	 */
	void Animation::applyTexture(sf::Sprite& sprite) {

		// Set sprite animation texture
		sprite.setTexture(texture);

		// Get current texture size
		sf::Vector2ui size = texture.getSize();

		// Set sprite draw origin to center
		sprite.setOrigin(size.x / 2.f, size.y / 2.f});
	};

}
