#pragma once

#include "BoardItem.h"

class Gate : public BoardItem {

public:
	Gate(Location location = { 0, 0 }, sf::Vector2f boardLocation = { 0, 0 });
	~Gate();

	bool handleCollision(Item* item) override;
	bool handleCollision(King* item);
	bool handleCollision(Thief* item);
	bool handleCollision(Mage* item);
	bool handleCollision(Warrier* item);
	bool handleCollision(Dwarf* item);

private:

	void openGate();
};