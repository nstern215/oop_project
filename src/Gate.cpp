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

bool Gate::handleCollision(Item* item)
{
	return item->handleCollision(this);
}

bool Gate::handleCollision(King* item)
{
	return false;
}

bool Gate::handleCollision(Thief* item)
{
	this->openGate();
	return false;
}

bool Gate::handleCollision(Mage* item)
{
	return false;
}

bool Gate::handleCollision(Warrier* item)
{
	return false;
}

bool Gate::handleCollision(Dwarf* item)
{
	return false;
}