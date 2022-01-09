#include "Wall.h"

Wall::Wall(Location location)
	:BoardItem(location)
{
}

Wall::~Wall()
{
}

void Wall::handleCollision(Item& item){}

void Wall::handleCollision(Characters& item){}

void Wall::handleCollision(Dwarf& item){}
