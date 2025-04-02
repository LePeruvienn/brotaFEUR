#include "core/Game.h"
#include "entities/Player.h"

int main() {

	Game& game = Game::getInstance ();

    Player player(200.f, 200.f);
	player.addInput ();
	game.add (&player);

	game.run();

	return 0;
}
