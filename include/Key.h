#pragma once

#include "BoardItem.h"

class Key : public BoardItem {

public:

	Key(Location location = { 0, 0 }, sf::Vector2f boardLocation = { 0, 0 }, sf::Vector2f itemSize = {80.f, 80.f});

	bool handleCollision(Item* item);
	bool handleCollision(Thief* item) override;
	void keyTaken();
};