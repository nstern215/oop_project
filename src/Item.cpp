#include "Item.h"

Item::Item(Location location)
	:m_location(location)
{
}

Item::~Item()
{
	delete m_itemInfo;
}

