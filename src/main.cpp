#include "core/Game.h"
#include "entities/player/Player.h"
#include "entities/mob/Mob.h"

int main() {

	Game& game = Game::getInstance ();

    Player player(200.f, 200.f);
    Mob mob(200.f, 200.f);

	player.addInput ();
	game.add (&player);
	game.add (&mob);

	game.run();

	return 0;
}
