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

void Key::keyTaken()
{
	m_active = false;
}

bool Key::handleCollision(Item* item)
{
	if (this == item)
		return false;

	return item->handleCollision(this);
}

bool Key::handleCollision(Thief* item)
{
	this->keyTaken();
	return true;
}