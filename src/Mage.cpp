#include "Mage.h"
#include "ResourcesService.h"

Mage::Mage(Location location)
	:Characters(location)
{

	sf::Texture* t = ResourcesService::instance()->getTexture("mage.png");

	//sf::Texture* t = new sf::Texture();
	//t->loadFromFile("crown.png");

	m_rectangle.setTexture(t, true);
}

Mage::~Mage()
{
}

void Mage::handleCollision(Fire& item)
{
}

void Mage::handleCollision(Gate& item)
{
}

void Mage::handleCollision(Item& item)
{
}

void Mage::handleCollision(Key& item)
{
}

void Mage::handleCollision(Ork& item)
{
}

void Mage::handleCollision(Teleport& item)
{
}

void Mage::handleCollision(Characters& item)
{
}

void Mage::handleCollision(Dwarf& item)
{
}

void Mage::handleCollision(Wall& item)
{
}

void Mage::handleCollision(Gift& item)
{
}

void Mage::handleCollision(Throne& item)
{
}
