#include "King.h"
#include "ResourcesService.h"

King::King(Location location, sf::Vector2f boardLocation)
	:Characters(location, boardLocation)
{
	m_throne = false;

	sf::Texture* t = ResourcesService::instance()->getTexture("crown.png");
	
	m_rectangle.setTexture(t, true);
}

void King::sitInThrone()
{
	m_throne = true;
}

bool King::isAtThrone()
{
	return m_throne;
}

bool King::handleCollision(Item* item)
{
	if (this == item)
		return false;

	return item->handleCollision(this);
}

bool King::handleCollision(Throne* item)
{
	this->sitInThrone();
	return true;
}