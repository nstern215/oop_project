#pragma once

#include "BoardItem.h"

class Key : public BoardItem {

public:

	Key(Location location = { 0, 0 }, sf::Vector2f boardLocation = { 0, 0 });
	~Key();

	bool handleCollision(Item& item);
	bool handleCollision(Characters& item);
	bool handleCollision(Dwarf& item);


private:

};