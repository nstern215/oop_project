#include "Teleport.h"
#include "ResourcesService.h"

Teleport::Teleport(Location location, Location pairLocation, sf::Vector2f boardLocation)
	:BoardItem(location, boardLocation),
	m_pairLocation(pairLocation)
{
	m_inUse = false;
	sf::Texture* t = ResourcesService::instance()->getTexture("teleport.png");

	//sf::Texture* t = new sf::Texture();
	//t->loadFromFile("crown.png");

	m_rectangle.setTexture(t, true);
}

void Teleport::getItemToPair()
{
	m_inUse = false;
}

bool Teleport::teleportInUse()
{
	m_inUse = true;

	return m_inUse;
}

bool Teleport::handleCollision(Item* item)
{
	if (this == item)
		return false;

	return item->handleCollision(this);
}

bool Teleport::handleCollision(King* item)
{
	this->teleportInUse();
	return true;
}

bool Teleport::handleCollision(Thief* item)
{
	this->teleportInUse();
	return true;
}

bool Teleport::handleCollision(Warrier* item)
{
	this->teleportInUse();
	return true;
}