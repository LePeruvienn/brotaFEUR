#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "../entities/Entity.h"
#include "../entities/Player.h"

class Game {
public:

	static Game& getInstance() {
		static Game instance;
		return instance;
	}

	// Delete copy constructors to prevent multiple instances
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	void run();
	void add(Entity* entity);
	void setPlayer1 (Player* player);

private:

	Game();
	~Game();

	void processInput();
	void update(sf::Time deltaTime);
	void render();

	sf::RenderWindow window;
	std::vector<Entity*> entities;

	Player* player1 = nullptr;
};

#endif
