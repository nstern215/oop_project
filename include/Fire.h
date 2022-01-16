#pragma once

#include "BoardItem.h"

class Fire : public BoardItem {

public:
	Fire(Location location = { 0, 0 }, sf::Vector2f boardLocation = { 0, 0 });

	bool handleCollision(Item* item);
	bool handleCollision(Mage* item) override;
	void putOutFire();
};