#include "Throne.h"
#include "ResourcesService.h"

Throne::Throne(Location location)
	:BoardItem(location)
{
	sf::Texture* t = ResourcesService::instance()->getTexture("throne.png");

	//sf::Texture* t = new sf::Texture();
	//t->loadFromFile("crown.png");

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
	return item->handleCollision(this);
}

bool Throne::handleCollision(King* item)
{
	this->KingIsAtThrone();
	return true;
}

bool Throne::handleCollision(Thief* item)
{
	return false;
}

bool Throne::handleCollision(Mage* item)
{
	return false;
}

bool Throne::handleCollision(Warrier* item)
{
	return false;
}

bool Throne::handleCollision(Dwarf* item)
{
	return false;
}