#pragma once

#include "BoardItem.h"

class Teleport : public BoardItem {

public:

	Teleport(Location location = { 0, 0 }, sf::Vector2f boardLocation = { 0, 0 });
	~Teleport();

	/*Teleport(Location pairLocation);

	Location launch();*/

	bool handleCollision(Item& item);
	bool handleCollision(Characters& item);
	bool handleCollision(Dwarf& item);

private:

	Location m_pairLocation;

};