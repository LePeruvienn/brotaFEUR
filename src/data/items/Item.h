// Force compiler to include this once
#ifndef ITEM_DATA_H
#define ITEM_DATA_H

#include <string>
#include "../Stats.h"

namespace Data {

	struct Item {

		std::string name;
		Data::Stats stats;
		int cost;
	};
}

#endif // ITEM_DATA_H
