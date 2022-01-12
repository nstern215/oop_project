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

bool Throne::handleCollision(Item& item)
{
	return item.handleCollision(this);
}

bool Throne::handleCollision(Characters& item)
{
	return false;
}

bool Throne::handleCollision(Dwarf& item)
{
	return false;
}
