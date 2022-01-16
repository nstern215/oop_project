#include "Thief.h"
#include "Key.h"
#include "Gate.h"
#include "Teleport.h"
#include "ResourcesService.h"

Thief::Thief(Location location, sf::Vector2f boardLocation)
	:Characters(location, boardLocation)
{
	m_key = false;

	m_rectangle.setTexture(ResourcesService::instance()->getTexture("thief.png"), true);
}

void Thief::collectKey() 
{
	m_rectangle.setTexture(ResourcesService::instance()->getTexture("thief_key.png"), true);
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
		m_rectangle.setTexture(ResourcesService::instance()->getTexture("thief_key.png"), true);
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

		m_rectangle.setTexture(ResourcesService::instance()->getTexture("thief.png"), true);
		return true;
	}
	return false;
}

bool Thief::handleCollision(Teleport* item)
{
	/*std::cout << "colition with teleport" << std::endl;*/
	return true;
}
