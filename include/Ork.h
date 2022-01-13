#pragma once

#include "BoardItem.h"

class Ork : public BoardItem {

public:
	
	Ork(Location location = { 0, 0 }, sf::Vector2f boardLocation = { 0, 0 });
	~Ork();

	bool handleCollision(Item* item) override;
	bool handleCollision(King* item);
	bool handleCollision(Warrier* item);
	bool handleCollision(Thief* item);
	bool handleCollision(Mage* item);
	bool handleCollision(Dwarf* item);
	void die();

private:

};