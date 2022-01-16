#include "Gift.h"
#include "ResourcesService.h"

Gift::Gift(Location location, sf::Vector2f boardLocation)
	:BoardItem(location, boardLocation)
{ 
	m_available = false;
	sf::Texture* t = ResourcesService::instance()->getTexture("gift.png");
	
	m_rectangle.setTexture(t, true);
}

Gift::~Gift()
{
}

bool Gift::handleCollision(Item& item)
{
	return item.handleCollision(this);
}

bool Gift::handleCollision(Dwarf& item)
{
	return false;
}

int Gift::useGift()
{
	return m_giftNum;
}
