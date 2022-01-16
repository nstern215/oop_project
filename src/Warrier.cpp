#include "Warrier.h"


#include "Teleport.h"
#include "Ork.h"
#include "ResourcesService.h"

#include <iostream>

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
	item->die();
	return true;
}

bool Warrier::handleCollision(Teleport* item)
{
	m_location = item->getPairLocation();

	updatePosition();

	std::cout << "Location " << m_location.m_col << ":" << m_location.m_row << std::endl;

	return false;
}
