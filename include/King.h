#pragma once

#include "Characters.h"

class King : public Characters {

public:

	King(ItemInfo* itemInfo = nullptr, Location location(0, 0), float positionOffsetX = 0, float positionOffsetY = 0);
private:

	bool gotToThrone(Location& location);

	bool m_throne;

};