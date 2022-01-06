#include "Ork.h"

Ork::Ork(Location location)
	:BoardItem(location)
{
}

Ork::~Ork()
{
}

void Ork::handleCollision(Item& item)
{
}

void Ork::handleCollision(Characters& item)
{
}

void Ork::handleCollision(Dwarf& item)
{
}
