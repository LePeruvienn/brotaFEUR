#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Entity {
public:
	Entity(float x = 50.f, float y = 50.f, float radius = 30.f, sf::Color color = sf::Color::Green);
	void update (sf::Time deltaTime);
	void render (sf::RenderWindow& window);

	sf::Vector2f pos;

protected:
	sf::CircleShape shape;
};

#endif // ENTITY_H
