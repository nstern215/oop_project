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
	sf::Texture* t = ResourcesService::instance()->getTexture("ork.png");

	m_rectangle.setTexture(t, true);
}

bool Ork::handleCollision(Item* item)
{
	return item->handleCollision(this);
}

bool Ork::handleCollision(King* item)
{
	return false;
}

bool Ork::handleCollision(Warrier* item)
{
	this->die();

	return true;
}

bool Ork::handleCollision(Thief* item)
{
	return false;
}

bool Ork::handleCollision(Mage* item)
{
	return false;
}

bool Ork::handleCollision(Dwarf* item)
{
	return false;
}