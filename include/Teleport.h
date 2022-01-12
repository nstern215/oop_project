#pragma once

#include "BoardItem.h"

class Teleport : public BoardItem {

public:

	Teleport(Location location = { 0, 0 }, Location pairLocation = { 0,0 }, sf::Vector2f boardLocation = { 0, 0 });
	~Teleport();

	/*Teleport(Location pairLocation);

	Location launch();*/

	bool handleCollision(Item* item) override;
	bool handleCollision(Characters* item) override;
	bool handleCollision(Dwarf* item) override;

private:

	Location m_pairLocation;

};