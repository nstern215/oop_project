#pragma once

#include "BoardItem.h"

class Wall : public BoardItem {

public:
	
	Wall(Location location = { 0, 0 });
	~Wall();

	bool handleCollision(Item* item) override;
	bool handleCollision(King* item);
	bool handleCollision(Warrier* item);
	bool handleCollision(Thief* item);
	bool handleCollision(Mage* item);
	bool handleCollision(Dwarf* item);

private:

};