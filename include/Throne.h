#pragma once

#include "BoardItem.h"

class Throne : public BoardItem {

public:
	
	Throne(Location location = { 0, 0 });
	~Throne();

	void handleCollision(Item& item);
	void handleCollision(Characters& item);
	void handleCollision(Dwarf& item);


private:

};