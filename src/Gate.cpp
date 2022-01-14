#include "Gate.h"
#include "ResourcesService.h"

Gate::Gate(Location location, sf::Vector2f boardLocation)
	:BoardItem(location, boardLocation)
{
	sf::Texture* t = ResourcesService::instance()->getTexture("fire.png");

	//sf::Texture* t = new sf::Texture();
	//t->loadFromFile("crown.png");

	m_rectangle.setTexture(t, true);
}

Gate::~Gate()
{
}

void Gate::openGate()
{
}

bool Gate::handleCollision(Characters* item)
{
	return false;
}