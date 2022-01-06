#pragma once

#include "BoardItem.h"

class Teleport : public BoardItem {

public:

	/*Teleport(Location pairLocation);

	Location launch();*/

	Teleport(Location location = { 0, 0 });
	~Teleport();

	void handleCollision(Item& item);
	void handleCollision(Characters& item);
	void handleCollision(Dwarf& item);

private:

	Location m_pairLocation;

};