#pragma once

#include "BoardItem.h"

class Ork : public BoardItem {

public:
	
	Ork(Location location = { 0, 0 }, sf::Vector2f boardLocation = { 0, 0 });
	~Ork();

	bool handleCollision(Item* item) override;
	bool handleCollision(Characters* item) override;
	bool handleCollision(Dwarf* item) override;

private:

};