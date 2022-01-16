#include "Ork.h"
#include "ResourcesService.h"

Ork::Ork(Location location, sf::Vector2f boardLocation)
	:BoardItem(location, boardLocation) 
{
	sf::Texture* t = ResourcesService::instance()->getTexture("ork.png");

	//sf::Texture* t = new sf::Texture();
	//t->loadFromFile("crown.png");

	m_rectangle.setTexture(t, true);
}

Ork::~Ork()
{
}

void Ork::die()
{
	m_isActive = false;
}

bool Ork::handleCollision(Item* item)
{
	if (this == item)
		return false;

	return item->handleCollision(this);
}

bool Ork::handleCollision(Warrier* item)
{
	this->die();
	return true;
}