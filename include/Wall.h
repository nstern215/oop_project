#pragma once

#include "BoardItem.h"

class Wall : public BoardItem {

public:
	
	Wall(Location location = { 0, 0 });
	~Wall();

	void handleCollision(Item& item);
	void handleCollision(Characters& item);
	void handleCollision(Dwarf& item);

private:

};