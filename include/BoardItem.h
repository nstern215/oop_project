#pragma once

#include "Item.h"
#include "Characters.h"
#include "Dwarf.h"

class BoardItem : public Item {

public:

	BoardItem(Location location = {0, 0}, sf::Vector2f boardLocation = { 0, 0 });
	~BoardItem();

protected:

	virtual bool handleCollision(Item& item) = 0;
	virtual bool handleCollision(Characters& item) = 0;
	virtual bool handleCollision(Dwarf& item) = 0;
};