#include "Throne.h"

Throne::Throne(Location location)
	:BoardItem(location)
{
}

Throne::~Throne()
{
}

void Throne::handleCollision(Item& item){}

void Throne::handleCollision(Characters& item){}

void Throne::handleCollision(Dwarf& item){}
