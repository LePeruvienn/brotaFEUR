#include "core/Game.h"
#include "entities/player/Player.h"
#include "entities/mob/Mob.h"

int main() {
	

	Game::init ();

	Player::Player player(200.f, 200.f);
	Mob::Mob mob(200.f, 200.f);

	player.addInput ();
	Game::add (&player);
	Game::add (&mob);

	Game::run();

	return 0;
}
