#pragma once

#include "BoardItem.h"

class Teleport : public BoardItem {

public:

	Teleport(Location location = { 0, 0 }, Location pairLocation = { 0,0 }, sf::Vector2f boardLocation = { 0, 0 });

	/*Teleport(Location pairLocation);

	Location launch();*/

	bool handleCollision(Item* item);
	bool handleCollision(King* item) override;
	bool handleCollision(Thief* item) override;
	bool handleCollision(Warrier* item) override;

	bool teleportInUse();
	Location getItemToPair();


private:

	bool m_inUse;

	Location m_pairLocation;

};