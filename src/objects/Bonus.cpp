#include "Bonus.h"
#include <iostream>
#include "../core/Game.h"
#include "../core/Physics.h"

/** @module Bonus */
namespace Bonus {

	std::vector<Bonus*> objects; ///< list of all the bonuses objects in the game

	/*
	 * Add a bonus to the bonuses list
	 * @param Bonus*
	 */
	void add (Bonus* bonus) {

		// Add the bonus to the objects list
		objects.push_back(bonus);
	}
	

	/**
	 * Create a new Bonus object instance, and add it to the game logic
	 * @param x - x axis position
	 * @param y - y axis position
	 * @param radius - entity body radius
	 * @param color - entity body color
	 * @return Bonus*
	 */
	Bonus* create(float x, float y, float radius, sf::Color color, Entity::Effect effect) {

		Bonus* bonus = new Bonus(x, y, radius, color, effect);

		Game::add(bonus);

		add(bonus);

		return bonus;
	}

	/**
	 * Bonus constructor
	 * @param x - x axis position
	 * @param y - y axis position
	 * @param radius - entity body radius
	 * @param color - entity body color
	 */
	Bonus::Bonus(float x, float y, float radius, sf::Color color, Entity::Effect effect)
		// Use the parent's constructor
		: Game::Object(x, y), shape(radius), effect(effect) {

		// Set shape position & color
		shape.setPosition({x, y});
		shape.setFillColor(color);

		// Create entity rigidShape
		rigidShape = new Physics::CircleRigidShape (x, y, 1.f, radius);

		// Set current object as rigidShape parent's
		rigidShape->setParent(this);

		// Add the rigidShape to the Physics
		Physics::addObject (rigidShape);
	};

	/**
	 * Updates the object's logic.
	 * @param deltaTime - The time elapsed since the last frame (in ms)
	 */
	void Bonus::update (float deltaTime) {
		
		// If an entity is currently touching a the bonus
		for (auto& rs : rigidShape->collisions) {
			
			// If rs parent is null go to next collisions
			if (rs->parent == nullptr) continue;

			// Cast object as an Entity
			// ⚠️ MUST USE dynamic_cast() otherwise it will not check if the current object is of the right type !!!
			Entity::Entity* entity = dynamic_cast<Entity::Entity*>(rs->parent);

			// If cast dosnt work go to next collisions
			if (entity == nullptr) continue;

			// apply the effect to the entity
			effect.apply(entity);

			// Destroy current object
			destroy();

			break;
		}
	};

	/*
	 * Callback function called before the entity is deleted
	 */
	void Bonus::onDestroy() {

		std::cout << "Bonus : onDestroy()" << std::endl;

		/*
		 * OPTIMIZE: We are looping all the entities loop for 1 entity,
		 * Maybe each frame we could loop once for each entites ? IDK 🤓
		 */

		// Search for current entity as remove it from the array
		for (int i = 0; i < objects.size(); i++) {
			
			// If we found current entity
			if (objects[i]->id == id) {
				
				// Erase it from entities array
				objects.erase(objects.begin() + i);

				// Go out the for loop
				break;
			}
		}

		// Use parent's function
		Object::onDestroy();
	}

	/**
	 * Renders the bonus to the specified window.
	 * @param window - Instance of the game window
	 */
	void Bonus::render(sf::RenderWindow& window) {

		// Set shape to bonus rigidShape current position
		shape.setPosition(rigidShape->pos);

		// Draw shape into the screen
		window.draw(shape);
	}
}
