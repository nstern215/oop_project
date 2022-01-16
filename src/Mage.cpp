#include "Mage.h"

#include <iostream>


#include "Fire.h"
#include "ResourcesService.h"

Mage::Mage(Location location, sf::Vector2f boardLocation)
	:Characters(location, boardLocation)
{

	sf::Texture* t = ResourcesService::instance()->getTexture("mage.png");

	m_rectangle.setTexture(t, true);
}

bool Mage::handleCollision(Item* item)
{
	if (this == item)
		return false;

	return item->handleCollision(this);
}

bool Mage::handleCollision(Fire* item)
{
	item->putOutFire();
	return true;
}