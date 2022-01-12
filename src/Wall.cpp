#include "Wall.h"
#include "ResourcesService.h"

Wall::Wall(Location location)
	:BoardItem(location)
{
	sf::Texture* t = ResourcesService::instance()->getTexture("wall.png");

	//sf::Texture* t = new sf::Texture();
	//t->loadFromFile("crown.png");

	m_rectangle.setTexture(t, true);
}

Wall::~Wall()
{
}

bool Wall::handleCollision(Item& item)
{
	return item.handleCollision(this);
}

bool Wall::handleCollision(Characters& item)
{
	return false;
}

bool Wall::handleCollision(Dwarf& item)
{
	return false;
}