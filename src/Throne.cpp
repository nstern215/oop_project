#include "Throne.h"
#include "ResourcesService.h"

Throne::Throne(Location location)
	:BoardItem(location)
{
	sf::Texture* t = ResourcesService::instance()->getTexture("throne.png");
	
	m_rectangle.setTexture(t, true);
}

Throne::~Throne()
{
}

void Throne::KingIsAtThrone()
{
}

bool Throne::handleCollision(Item* item)
{
	if (this == item)
		return false;

	return item->handleCollision(this);
}

bool Throne::handleCollision(King* item)
{
	return true;
}