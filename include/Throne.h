#pragma once

#include "BoardItem.h"

class Throne : public BoardItem {

public:
	
	Throne(Location location = { 0, 0 });
	~Throne();

	bool handleCollision(Item& item);
	bool handleCollision(Characters& item);
	bool handleCollision(Dwarf& item);


private:

};