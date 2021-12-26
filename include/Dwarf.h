#pragma once

#include "Characters.h"

class Dwarf : public Characters {

public:
	Dwarf(ItemInfo* itemInfo = nullptr, Location location(0, 0), float positionOffsetX = 0, float positionOffsetY = 0);

private:

	/*void move(sf::Vector2f destination);*/

};