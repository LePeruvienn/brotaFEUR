#ifndef ANIMATOR_H // Make the compiler include this once
#define ANIMATOR_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Animation.h"

/** @module Render */
namespace Render {

	/**
	 * Animations manager for a sprite
	 */
	class Animator {
	public:

		/**
		 * Animator constructor
		 * @param vector<Animation*> - all current Animator animations pointers
		 */
		Animator(std::vector<Animation*> animations);

		/**
		 * Player animation on a sprite
		 * @param index - animation index to play
		 */
		void play(int index);

		/**
		 * Update current animator
		 * @param deltaTime - time eleapsed between now and the last frame
		 */
		void update(float deltaTime);

		/**
		 * Renders the animation to the specified window.
		 * @param window - Instance of the game window
		 */
		void render(sf::RenderWindow& window);

	private:
		
		std::vector<Animation*> animations;

		sf::Sprite* sprite = nullptr; ///< Sprite used for the animation

		int currentIndex = 0; ///< Current animation index played
		Animation* currentAnimation = nullptr; ///< Current animation playing
		int currentFrame = 0; ///< Current frame we are
		float timer = 0.f; ///< Time eleapsed since the begin of the current frame
	};
}

#endif // ANIMATOR_H
