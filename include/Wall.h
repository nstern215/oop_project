#pragma once

#include "BoardItem.h"

class Wall : public BoardItem {

public:
	
	Wall(Location location = { 0, 0 });
	~Wall();

	bool handleCollision(Item& item);
	bool handleCollision(Characters& item);
	bool handleCollision(Dwarf& item);

private:

};