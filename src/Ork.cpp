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

bool Ork::handleCollision(Characters* item)
{
	return false;
}