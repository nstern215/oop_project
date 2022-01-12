#pragma once

#include "Gift.h"

class EmptyGift : public Gift {

public:

	EmptyGift(Location location = { 0, 0 }, sf::Vector2f boardLocation = { 0, 0 });
	~EmptyGift();

	bool handleCollision(Characters& item);
};