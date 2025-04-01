#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "../entities/Entity.h"

class Game {
public:
	Game();
	void run();
	void add(Entity entity);

private:
	void processInput();
	void update(sf::Time deltaTime);
	void render();

	sf::RenderWindow window;
	std::vector<Entity> entities;
};

#endif
