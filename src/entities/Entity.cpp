#include "Entity.h"

Entity::Entity(float x, float y, float radius, sf::Color color) {

	pos = sf::Vector2f(x, y);
	shape = sf::CircleShape(radius);
	shape.setPosition(pos);
	shape.setFillColor(color);
}

void Entity::update(float delta) {

}

void Entity::render(sf::RenderWindow& window) {

	window.draw(shape);
}
