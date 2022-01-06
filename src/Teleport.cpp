#include "Teleport.h"

Teleport::Teleport(Location location)
	:BoardItem(location)
{
}

Teleport::~Teleport()
{
}

void Teleport::handleCollision(Item& item){}

void Teleport::handleCollision(Characters& item){}

void Teleport::handleCollision(Dwarf& item) {}