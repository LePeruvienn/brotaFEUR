#include "core/Game.h"

int main() {

	Game game;

	Entity entity(300.f, 300.f, 100.f, sf::Color::Red);
	game.add(entity);

	game.run();

	return 0;
}
