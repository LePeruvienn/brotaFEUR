// Fore the compiler to include this once
#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../stats/Stats.h"
#include "../core/Object.h"
#include "../core/rigidShapes/RigidShape.h"
#include "../core/rigidShapes/CircleRigidShape.h"

namespace Entity {

	/**
	 * Abstract class representing a generic entity in the game
	 *
	 * This class serves as a base for all entities that can be rendered and updated
	 * in the game. It provides basic functionality for position and shape
	 */
	class Entity : public Game::Object {
	public:

		Stats stats; ///< Stats class to handle all entiteis stats
		float radius; ///< Current entity radius
		sf::CircleShape shape; ///< Shape representing the entity.
		Physics::RigidShape* rigidShape = nullptr; //< RigidShape linked to the entity

		/**
		 * constructs a new entity object with specified parameters.
		 * @param x - x axis position
		 * @param y - y axis position
		 * @param radius - entity body radius
		 * @param color - entity body color
		 * @param stats - entities stats
		 */
		Entity(
			float x = 50.f,
			float y = 50.f,
			float radius = 30.f,
			sf::Color color = sf::Color::Green,
			Stats stats = Stats ()
		);

		/**
		 * Virtual destructor for the Entity class.
		 * This ensures that derived classes' destructors are called properly
		 */
		virtual ~Entity() = default;

		/**
		 * Renders the entity to the specified window.
		 * @param window - Instance of the game window
		 */
		virtual void render(sf::RenderWindow& window) override;
	};

	extern std::vector<Entity*> entities; ///< Game entities list

	/**
	 * Add an entity to the entities list
	 * @param Entity*
	 */
	void add(Entity* entity);
}

#endif // ENTITY_H
