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

bool Throne::handleCollision(Characters* item)
{
	return false;
}