#include "Thief.h"

#include "ResourcesService.h"

Thief::Thief(Location location, sf::Vector2f boardLocation)
	:Characters(location, boardLocation)
{
	m_rectangle.setTexture(ResourcesService::instance()->getTexture("thief.png"), true);
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
	if (this == item)
		return false;

	return item->handleCollision(this);
}

bool Thief::handleCollision(Key* item)
{
	this->collectKey();
	return true;
}
