#pragma once

#include "BoardItem.h"

class Fire : public BoardItem {

public:
	Fire(Location location = { 0, 0 }, sf::Vector2f boardLocation = { 0, 0 });
	~Fire();

	bool handleCollision(Item* item) override;
	bool handleCollision(King* item);
	bool handleCollision(Warrier* item);
	bool handleCollision(Thief* item);
	bool handleCollision(Mage* item);
	bool handleCollision(Dwarf* item);

private:

	void putOutFire();
};