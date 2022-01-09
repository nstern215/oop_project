#pragma once

#include "BoardItem.h"

class Ork : public BoardItem {

public:
	
	Ork(Location location = { 0, 0 });
	~Ork();

	void handleCollision(Item& item);
	void handleCollision(Characters& item);
	void handleCollision(Dwarf& item);

private:

};