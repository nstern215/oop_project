#include "Mage.h"
#include "ResourcesService.h"

Mage::Mage(Location location, sf::Vector2f boardLocation)
	:Characters(location, boardLocation)
{

	sf::Texture* t = ResourcesService::instance()->getTexture("mage.png");

	//sf::Texture* t = new sf::Texture();
	//t->loadFromFile("crown.png");

	m_rectangle.setTexture(t, true);
}

Mage::~Mage()
{
}

bool Mage::gotToEdge()
{
	return false;
}

bool Mage::handleCollision(Item* item)
{
	if(item == this)
	return false;

	return item->handleCollision(this);
}

bool Mage::handleCollision(Fire* item)
{
	return true;
}

bool Mage::handleCollision(Teleport* item)
{
	return true;
}

bool Mage::handleCollision(Gift* item)
{
	return true;
}

bool Mage::handleCollision(Key* item)
{
	return true;
}

bool Mage::handleCollision(Ork* item)
{
	return false;
}

bool Mage::handleCollision(Throne* item)
{
	return false;
}

bool Mage::handleCollision(Gate* item) 
{
	return false;
}

bool Mage::handleCollision(Characters* item) 
{
	return false;
}

bool Mage::handleCollision(Dwarf* item)
{
	return false;
}

bool Mage::handleCollision(Wall* item)
{
	return false;
}