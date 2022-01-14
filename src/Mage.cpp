#include "Mage.h"

#include <iostream>

#include "ResourcesService.h"

Mage::Mage(Location location, sf::Vector2f boardLocation)
	:Characters(location, boardLocation)
{

	sf::Texture* t = ResourcesService::instance()->getTexture("mage.png");

	//sf::Texture* t = new sf::Texture();
	//t->loadFromFile("crown.png");

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
	return true;
}

void Mage::putOutFire()
{
}
