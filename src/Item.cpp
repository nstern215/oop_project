#include "Item.h"

Item::Item(Location location, sf::Vector2f boardLocation, float speedPerSecond):
	m_location(location),
	m_boardLocation(boardLocation),
	m_speedPerSecond(speedPerSecond),
	m_active(true)
{
	m_rectangle.setSize({80.f, 80.f});

	sf::Vector2f position(m_location.m_col * 80.f, m_location.m_row * 80.f);
	position += boardLocation;
	
	m_rectangle.setPosition(position);
}

Item::~Item()
{}

void Item::draw(sf::RenderWindow& window)
{
	window.draw(m_rectangle);
}

void Item::setBoardLocation(sf::Vector2f position)
{
	auto currentPosition = m_rectangle.getPosition();
	currentPosition -= m_boardLocation;
	
	m_boardLocation = position;

	currentPosition += m_boardLocation;

	m_rectangle.setPosition(position);
}

sf::Vector2f Item::getPosition() const
{
	return m_rectangle.getPosition();
}

Location Item::getLocation() const
{
	return m_location;
}
