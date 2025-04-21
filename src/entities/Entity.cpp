#include "Entity.h"
#include "../core/Physics.h"

/** @module Entity */
namespace Entity {

	std::vector<Entity*> entities; ///< Game entities list

	/**
	 * Adds an new entity to the game !
	 * It adds the entity to the entities list of the game instance
	 * So the game loop will now update this entity
	 * @param entity - entity instance reference
	 */
	void add(Entity* entity) {

		// Add entity to game entities list
		entities.push_back(entity);
	}

	/**
	 * constructs a new entity object with specified parameters.
	 * @param x - x axis position
	 * @param y - y axis position
	 * @param radius - entity body radius
	 * @param color - entity body color
	 */
	Entity::Entity(float x, float y, float radius, sf::Color color, Stats stats)
		// Intialize class values
		: Game::Object(x, y), shape(radius), stats(stats) {

		// Set shape position & color
		shape.setPosition({x, y});
		shape.setFillColor(color);

		// Create entity rigidShape
		rigidShape = new Physics::CircleRigidShape (x, y, 1.f, radius);

		// Set current entity as rigidShape parent's
		rigidShape->setParent(this);

		// Add the rigidShape to the Physics
		Physics::addObject (rigidShape);
	}

	/*
	 * Callback function called before the entity is deleted
	 */
	void Entity::onDestroy() {

		/*
		 * OPTIMIZE: We are looping all the entities loop for 1 entity,
		 * Maybe each frame we could loop once for each entites ? IDK 🤓
		 */

		// Search for current entity as remove it from the array
		for (int i = 0; i < entities.size(); i++) {
			
			// If we found current entity
			if (entities[i]->id == id) {
				
				// Erase it from entities array
				entities.erase(entities.begin() + i);

				// Go out the for loop
				break;
			}
		}

		// Remove rigidShape from Physics
		Physics::removeObject(rigidShape);
	
		// Remove rigidShape from the memory
		delete rigidShape;

		// Use parent's function
		Game::Object::onDestroy();
	}

	/**
	 * Updates the entity's logic.
	 * @param deltaTime - The time elapsed since the last frame (in ms)
	 */
	void Entity::update(float deltaTime) {
		
		pos.x = rigidShape->pos.x;	
		pos.y = rigidShape->pos.y;	

		// Use parent's update function !
		Game::Object::update(deltaTime);
	}

	/**
	 * Renders the object to the specified window.
	 * @param window - Instance of the game window
	 */
	void Entity::render(sf::RenderWindow& window) {

		// Use parent's render function !
		Game::Object::render(window);

		// Set shape to player rigidShape current position
		shape.setPosition(rigidShape->pos);

		// Draw shape into the screen
		window.draw(shape);
	}
}
