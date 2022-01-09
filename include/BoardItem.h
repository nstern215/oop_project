#pragma once

#include "Item.h"
#include "Characters.h"
#include "Dwarf.h"

class BoardItem : public Item {

public:

	BoardItem(Location location = {0, 0});

protected:

	virtual void handleCollision(Item& item) = 0;
	virtual void handleCollision(Characters& item) = 0;
	virtual void handleCollision(Dwarf& item) = 0;

private:

};