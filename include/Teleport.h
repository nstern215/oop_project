#pragma once

#include "BoardItem.h"

class Teleport : public BoardItem {

public:

	Teleport(Location location = { 0, 0 }, Location pairLocation = { 0,0 }, sf::Vector2f boardLocation = { 0, 0 });
	~Teleport();

	/*Teleport(Location pairLocation);

	Location launch();*/

	bool handleCollision(Item* item) override;
	bool handleCollision(King* item);
	bool handleCollision(Warrier* item);
	bool handleCollision(Thief* item);
	bool handleCollision(Mage* item);
	bool handleCollision(Dwarf* item);

private:

	void getItemToPair();

	Location m_pairLocation;

};