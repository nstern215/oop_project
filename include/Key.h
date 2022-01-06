#pragma once

#include "BoardItem.h"

class Key : public BoardItem {

public:

	Key(Location location = { 0, 0 });
	~Key();

	void handleCollision(Item& item);
	void handleCollision(Characters& item);
	void handleCollision(Dwarf& item);


private:

};