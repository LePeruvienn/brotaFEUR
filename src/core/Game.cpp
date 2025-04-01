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
    // Ajoute ici la logique de mise à jour (déplacement, etc.)
}

void Game::render() {

    window.clear(sf::Color::Black);
    window.display();
}
