#include "Textures.h"

/** @module Render */
namespace Resources {

	/** @module Render::Texture */
	namespace Texture {

		std::unordered_map<std::string, sf::Texture> textureCache; ///< Cached textures datas
		
		/* Get the texture in the file path in parameter
		 * @param path - file path of the texture
		 */
		sf::Texture& get(std::string filepath) {

			// Check if the texture is already in the cache
			auto it = textureCache.find(filepath);

			// IF we found a texture, return the cached one
			if (it != textureCache.end())
				return it->second;

			// If not in cache, load the texture
			sf::Texture texture;

			// If we dont attemps to load the file, we throw an error !
			if (!texture.loadFromFile(filepath))
				std::cerr << "Failed to load texture: " << filepath << std::endl;

			// If we succefully load the file, we saved it in the cache
			textureCache[filepath] = texture;

			// Return the reference of the cached texture
			return textureCache[filepath];
		}

		/* 
		 * Clear all the cached textures datas
		 */
		void clear() {

			// Reset the texture cache map
			textureCache.clear();
		}
	}
}
