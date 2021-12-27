#pragma once

#include "Item.h"
#include "Characters.h"
#include "Dwarf.h"

class BoardItem : public Item {

public:

	BoardItem(Location location = {0, 0});

protected:

	void handleCollision(Item& item);
	void handleCollision(Characters& item);
	void handleCollision(Dwarf& item);

private:

};