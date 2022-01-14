#pragma once

#include "BoardItem.h"

class Wall : public BoardItem {

public:
	
	Wall(Location location = { 0, 0 });

	bool handleCollision(Item* item);

private:

};