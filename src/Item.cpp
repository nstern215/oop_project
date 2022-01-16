#include "Item.h"

Item::Item(Location location, sf::Vector2f boardLocation, float speedPerSecond):
	m_location(location),
	m_boardLocation(boardLocation),
	m_speedPerSecond(speedPerSecond),
	m_isActive(false)
{
	m_rectangle.setSize({80.f, 80.f});

	sf::Vector2f position(m_location.m_col * 80.f, m_location.m_row * 80.f);
	position += m_boardLocation;
	
	m_rectangle.setPosition(position);
}

Item::~Item()
{}

void Item::draw(sf::RenderWindow& window)
{
	window.draw(m_rectangle);
}

void Item::setActive(bool active)
{
	m_isActive = active;
}

bool Item::isActive() const
{
	return m_isActive;
}

void Item::setBoardLocation(sf::Vector2f position)
{
	auto currentPosition = m_rectangle.getPosition();
	currentPosition -= m_boardLocation;

	m_boardLocation = position;

	currentPosition += m_boardLocation;

	m_rectangle.setPosition(currentPosition);
}

sf::Vector2f Item::getPosition() const
{
	return m_rectangle.getPosition();
}

Location Item::getLocation() const
{
	return m_location;
}

void Item::setSize(sf::Vector2f size)
{
	m_rectangle.setSize(size);

	sf::Vector2f position(m_location.m_col * size.x, m_location.m_row * size.y);
	position += m_boardLocation;

	m_rectangle.setPosition(position);
}

void Item::updatePosition()
{
	const auto size = m_rectangle.getSize();
	const sf::Vector2f newPosition = { m_location.m_col * size.x + m_boardLocation.x,
								m_location.m_row * size.y + m_boardLocation.y };

	m_rectangle.setPosition(newPosition);
}

bool Item::handleCollision(King* item)
{
	return false;
}

bool Item::handleCollision(Thief* item)
{
	return false;
}

bool Item::handleCollision(Mage* item)
{
	return false;
}

bool Item::handleCollision(Warrier* item)
{
	return false;
}

bool Item::handleCollision(Dwarf* item)
{
	return false;
}

bool Item::handleCollision(Wall* item)
{
	return false;
}

bool Item::handleCollision(Key* item)
{
	return true;
}

bool Item::handleCollision(Teleport* item)
{
	return true;
}

bool Item::handleCollision(Fire* item)
{
	return false;
}

bool Item::handleCollision(Gate* item)
{
	return false;
}

bool Item::handleCollision(Ork* item)
{
	return false;
}

bool Item::handleCollision(Throne* item)
{
	return false;
}