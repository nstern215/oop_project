#include "Teleport.h"
#include "ResourcesService.h"

Teleport::Teleport(Location location, Location pairLocation, sf::Vector2f boardLocation)
	:BoardItem(location, boardLocation),
	m_pairLocation(pairLocation)
{
	sf::Texture* t = ResourcesService::instance()->getTexture("teleport.png");

	//sf::Texture* t = new sf::Texture();
	//t->loadFromFile("crown.png");

	m_rectangle.setTexture(t, true);
}

Teleport::~Teleport()
{
}

void Teleport::getItemToPair()
{
}

bool Teleport::handleCollision(Characters* item)
{
	return false;
}