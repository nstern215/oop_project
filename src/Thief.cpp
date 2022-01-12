#include "Thief.h"

#include "ResourcesService.h"

Thief::Thief(Location location)
	:Characters(location)
{
	m_rectangle.setTexture(ResourcesService::instance()->getTexture("thief.png"), true);
}

Thief::~Thief()
{
}

void Thief::collectKey() 
{
	m_key = true;
}

bool Thief::gotKey()
{
	return m_key;
}

bool Thief::handleCollision(Item* item)
{
	if (item == this)
		return false;

	return item->handleCollision(this);
}

bool Thief::handleCollision(Gate* item)
{
	if (m_key == true)
	{
		m_key = false;
		return true;
	}

	return false;
}

bool Thief::handleCollision(Key* item)
{
	this->collectKey();

	return true;
}

bool Thief::handleCollision(Gift* item)
{
	return true;
}

bool Thief::handleCollision(Teleport* item)
{
	return true;
}

bool Thief::handleCollision(Ork* item)
{
	return false;
}

bool Thief::handleCollision(Throne* item)
{
	return false;
}

bool Thief::handleCollision(Fire* item)
{
	return false;
}

bool Thief::handleCollision(Characters* item)
{
	return false;
}

bool Thief::handleCollision(Dwarf* item)
{
	return false;
}

bool Thief::handleCollision(Wall* item)
{
	return false;
}