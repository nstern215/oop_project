#include "Key.h"

Key::Key(Location location)
	:BoardItem(location)
{
}

Key::~Key()
{
}

void Key::handleCollision(Item& item)
{
}

void Key::handleCollision(Characters& item)
{
}

void Key::handleCollision(Dwarf& item)
{
}
