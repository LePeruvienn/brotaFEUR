#include <thread>
#include "cli/CLI.h"
#include "cli/Logger.h"

#include "core/Game.h"
#include "entities/player/Player.h"
#include "entities/mob/Mob.h"
#include "objects/Bonus.h"


int main() {

	// Run CLI thread
	std::thread cli(CLI::run);

	// Init Logger module
	Logger::init();

	// Init game module
	Game::init();

	Player::Player* player = Player::create(800.f, 800.f);
	Mob::Mob* mob = Mob::create(200.f, 200.f);
	Bonus::Bonus* bonus = Bonus::create(500.f, 500.f, 20.f);

	// Add input to main player
	player->addInput ();
	Player::setPlayer1(player);
	Game::setPlayer1(player);

	// Run game
	Game::run();

	// End CLI thread on exit
    cli.join();

	// Flush Logger module
	Logger::flush();

	return 0;
}
