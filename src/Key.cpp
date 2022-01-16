#include "Key.h"
#include "ResourcesService.h"

Key::Key(Location location, sf::Vector2f boardLocation, sf::Vector2f itemSize)
	:BoardItem(location, boardLocation)
{
	m_isActive = true;
	
	sf::Texture* t = ResourcesService::instance()->getTexture("key.png");
	m_rectangle.setTexture(t, true);

	Item::setSize(itemSize);
}

void Key::keyTaken()
{
	m_isActive = false;
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