#include "Item.h"

Item::Item(Location location)
	:m_location(location)
{
}

void Item::setPosition(sf::Vector2f position)
{
	m_rectangle.setPosition(position);
}

sf::Vector2f Item::getPosition() const
{
	return m_rectangle.getPosition();
}
