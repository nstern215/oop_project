#include "Warrier.h"

Warrier::Warrier(Location location)
	:Characters(location)
{
}

Warrier::~Warrier()
{
}

bool Warrier::handleCollision(Item* item)
{
	if (item == this)
		return false;

	return item->handleCollision(this);
}

bool Warrier::handleCollision(Gift* item)
{
	return true;
}

bool Warrier::handleCollision(Teleport* item)
{
	return true;
}

bool Warrier::handleCollision(Ork* item)
{
	return true;
}

bool Warrier::handleCollision(Key* item)
{
	return true;
}

bool Warrier::handleCollision(Throne* item)
{
	return false;
}

bool Warrier::handleCollision(Gate* item)
{
	return false;
}

bool Warrier::handleCollision(Fire* item)
{
	return false;
}

bool Warrier::handleCollision(Characters* item)
{
	return false;
}

bool Warrier::handleCollision(Dwarf* item)
{
	return false;
}

bool Warrier::handleCollision(Wall* item)
{
	return false;
}