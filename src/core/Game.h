#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../entities/Entity.h"

class Game {
public:
	Game();
	void run();
	void add();

private:
	void processInput();
	void update(sf::Time deltaTime);
	void render();

	sf::RenderWindow window;
};

#endif
