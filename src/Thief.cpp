#include "Thief.h"


#include "Key.h"
#include "Gate.h"
#include "ResourcesService.h"

Thief::Thief(Location location, sf::Vector2f boardLocation)
	:Characters(location, boardLocation)
{
	m_key = false;

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
	if(!m_key)
	{
		item->keyTaken();
		m_key = true;
	}
	return true;
}

bool Thief::handleCollision(Gate* item)
{
	if (m_key)
	{
		item->openGate();
		m_key = false;
		return true;
	}
	return false;
}
