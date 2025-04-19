#include "core/Game.h"
#include "entities/player/Player.h"
#include "entities/mob/Mob.h"
#include "objects/Bonus.h"
#include "objects/Projectile.h"

int main() {
	

	Game::init ();

	Player::Player* player = Player::create(200.f, 200.f);
	Mob::Mob* mob = Mob::create(200.f, 200.f);
	Bonus::Bonus* bonus = Bonus::create(500.f, 500.f, 20.f);
	Projectile::Projectile* projectile = Projectile::create (250.f, 250.f);

	// Add input to main player
	player->addInput ();
	Player::setPlayer1(player);

	// Run game
	Game::run();

	return 0;
}
