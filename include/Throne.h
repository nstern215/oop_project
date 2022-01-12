#pragma once

#include "BoardItem.h"

class Throne : public BoardItem {

public:
	
	Throne(Location location = { 0, 0 });
	~Throne();

	bool handleCollision(Item* item) override;
	bool handleCollision(Characters* item) override;
	bool handleCollision(Dwarf* item) override;


private:

};