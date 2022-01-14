#pragma once

#include "BoardItem.h"

class Fire : public BoardItem {

public:
	Fire(Location location = { 0, 0 }, sf::Vector2f boardLocation = { 0, 0 });
	~Fire();

	bool handleCollision(Characters* item) override;

private:

	void putOutFire();
};