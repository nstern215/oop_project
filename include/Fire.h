#pragma once

#include "BoardItem.h"

class Fire : public BoardItem {

public:
	Fire(Location location = { 0, 0 }, sf::Vector2f boardLocation = { 0, 0 });
	~Fire();

	bool handleCollision(Item& item);
	bool handleCollision(Characters& item);
	bool handleCollision(Dwarf& item);

private:

};