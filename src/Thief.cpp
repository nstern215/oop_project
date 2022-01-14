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

bool Thief::handleCollision(Characters* item)
{
	return false;
}