#pragma once

#include "Item.h"

class BoardItem : public Item {

public:

	BoardItem(Location location = {0, 0}, sf::Vector2f boardLocation = { 0, 0 });
	virtual ~BoardItem();

protected:
};