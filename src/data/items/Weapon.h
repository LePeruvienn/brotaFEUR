// Force compiler to include this once
#ifndef WEAPON_DATA_H
#define WEAPON_DATA_H

#include <string>
#include "Item.h"
#include "../Stats.h"

namespace Data {

	struct Weapon : Item  {

		float fireRate;
	};
}

#endif // WEAPON_DATA_H
