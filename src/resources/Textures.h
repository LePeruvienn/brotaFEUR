#include <string>
#include <iostream>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


/** @module Render */
namespace Resources {

	/** @module Render::Texture */
	namespace Texture {

		extern std::unordered_map<std::string, sf::Texture> textureCache; ///< Cached textures datas
		
		/* Get the texture in the file path in parameter
		 * @param filepath - file path of the texture
		 */
		sf::Texture& get(std::string filepath);

		/* 
		 * Clear all the cached textures datas
		 */
		void clear();
	}
}
