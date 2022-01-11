#include "Teleport.h"
#include "ResourcesService.h"

Teleport::Teleport(Location location, sf::Vector2f boardLocation)
	:BoardItem(location, boardLocation)
{
	sf::Texture* t = ResourcesService::instance()->getTexture("teleport.png");

	//sf::Texture* t = new sf::Texture();
	//t->loadFromFile("crown.png");

	m_rectangle.setTexture(t, true);
}

Teleport::~Teleport()
{
}

bool Teleport::handleCollision(Item& item)
{
	return item.handleCollision(this);
}

bool Teleport::handleCollision(Characters& item)
{
	/*if(item == )*/
	return true;
}

bool Teleport::handleCollision(Dwarf& item)
{
	return false;
}