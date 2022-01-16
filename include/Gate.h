#pragma once

#include "BoardItem.h"

class Gate : public BoardItem {

public:
	Gate(Location location = { 0, 0 }, sf::Vector2f boardLocation = { 0, 0 });

	bool handleCollision(Item* item);
	bool handleCollision(Thief* item) override;

	void openGate();

private:
};