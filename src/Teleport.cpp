#include "Teleport.h"

#include <iostream>
#include "ResourcesService.h"

Teleport::Teleport(Location location, Location pairLocation, sf::Vector2f boardLocation)
	:BoardItem(location, boardLocation),
	m_pairLocation(pairLocation)
{
	m_inUse = false;
	sf::Texture* t = ResourcesService::instance()->getTexture("teleport.png");

	m_rectangle.setTexture(t, true);
}

Location Teleport::getPairLocation()
{
	return m_pairLocation;
}


bool Teleport::handleCollision(Item* item)
{
	return item->handleCollision(this);
}

bool Teleport::handleCollision(King* item)
{
	std::cout << "colition with king" << std::endl;
	return true;
}

bool Teleport::handleCollision(Thief* item)
{
	std::cout << "colition with thief" << std::endl;
	return true;
}

bool Teleport::handleCollision(Warrier* item)
{
	std::cout << "colition with warrier" << std::endl;

	return true;
}