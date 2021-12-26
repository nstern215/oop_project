#include "Characters.h"
#include "..\include\Characters.h"

Characters::Characters(Location location)
	:Item(location)
{
}

void Characters::handleCollision(Characters& item)
{
}

void Characters::handleCollision(Dwarf& item)
{
}

void Characters::handleCollision(Wall& item)
{
}

void Characters::handleCollision(Gift& item)
{
}
