#include "Game.h"
#include <optional>


Game::Game() {

	window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
}

void Game::run() {

    sf::Clock clock;

	// Game Loop
    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();
        processInput();
        update(deltaTime);
        render();
    }
}

void Game::add(Entity entity) {
    entities.push_back(entity);
}

void Game::processInput() {

	while (const std::optional event = window.pollEvent())
	{
		if (event->is<sf::Event::Closed>())
		{
			window.close();
		}
	}
}

void Game::update(sf::Time deltaTime) {
	for (auto& entity : entities) {
		entity.update(deltaTime);
	}
}

void Game::render() {

    window.clear(sf::Color::Black);
	for (auto& entity : entities) {
		entity.render(window);
	}
    window.display();
}
