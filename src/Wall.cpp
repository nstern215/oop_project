#include "Wall.h"
#include "ResourcesService.h"

Wall::Wall(Location location)
	:BoardItem(location)
{
	sf::Texture* t = ResourcesService::instance()->getTexture("wall.jpg");

	m_rectangle.setTexture(t, true);
}

bool Wall::handleCollision(Item* item)
{
	if (this == item)
		return false;

	return item->handleCollision(this);
}