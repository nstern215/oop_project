#include "Key.h"
#include "ResourcesService.h"

Key::Key(Location location, sf::Vector2f boardLocation)
	:BoardItem(location, boardLocation)
{
	sf::Texture* t = ResourcesService::instance()->getTexture("key.png");

	//sf::Texture* t = new sf::Texture();
	//t->loadFromFile("crown.png");

	m_rectangle.setTexture(t, true);
}

Key::~Key()
{
}

void Key::keyTaken()
{

}

bool Key::handleCollision(Item& item)
{
	return item.handleCollision(this);
}

bool Key::handleCollision(King* item)
{
	return true;
}

bool Key::handleCollision(Warrier* item)
{
	return true;
}

bool Key::handleCollision(Thief* item)
{
	this->keyTaken();

	return true;
}

bool Key::handleCollision(Mage* item)
{
	return true;
}

bool Key::handleCollision(Dwarf& item)
{
	return true;
}