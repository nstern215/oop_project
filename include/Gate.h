#pragma once

#include "BoardItem.h"

class Gate : public BoardItem {

public:
	Gate(Location location = { 0, 0 }, sf::Vector2f boardLocation = { 0, 0 });
	~Gate();

	bool handleCollision(Characters* item) override;

private:

	void openGate();
};