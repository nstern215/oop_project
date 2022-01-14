#include "Warrier.h"

#include "ResourcesService.h"

Warrier::Warrier(Location location, sf::Vector2f boardLocation)
	:Characters(location, boardLocation)
{
	m_rectangle.setTexture(ResourcesService::instance()->getTexture("warrior.png"), true);
}

bool Warrier::handleCollision(Item* item)
{
	if (this == item)
		return false;

	return item->handleCollision(this);
}

bool Warrier::handleCollision(Ork* item)
{
	return true;
}
