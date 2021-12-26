#include "BoardItems.h"


BoardItem::BoardItem(Location location)
	:Item(location)
{
}

void BoardItem::handleCollision(Item& item)
{
	item.handleCollision(*this);
}

void BoardItem::handleCollision(Characters& item)
{
	item.handleCollision(*this);
}

void BoardItem::handleCollision(Dwarf& item)
{
	item.handleCollision(*this);
}
