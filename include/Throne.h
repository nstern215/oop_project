#pragma once

#include "BoardItem.h"

class Throne : public BoardItem {

public:
	
	Throne(Location location = { 0, 0 });
	~Throne();

	bool handleCollision(Item* item) override;
	bool handleCollision(King* item);
	bool handleCollision(Thief* item);
	bool handleCollision(Mage* item);
	bool handleCollision(Warrier* item);
	bool handleCollision(Dwarf* item);

private:

	void KingIsAtThrone();
};