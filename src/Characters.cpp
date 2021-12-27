#include "Characters.h"

Characters::Characters(Location location) :
	Item(location),
	m_isActive(false)
{
}

Characters::~Characters()
{
	
}

void Characters::move(sf::Vector2f destination, float deltaTime)
{
	if (m_isActive)
	{
		calcNewLocation(destination);
		
		sf::Vector2f dest = destination * deltaTime * m_speedPerSecond;
		m_rectangle.move(dest);
	}
}

Location Characters::calcNewLocation(sf::Vector2f direction)
{
	sf::Vector2f size = m_rectangle.getSize();
	size /= 2.f;
	sf::Vector2f center = m_rectangle.getPosition();
	center += size;
	
	return m_location;
}


bool Characters::isActive() const
{
	return m_isActive;
}

void Characters::setActive(bool active)
{
	if (active)
		m_rectangle.setFillColor(sf::Color::Black);
	else
		m_rectangle.setFillColor(sf::Color::White);
	
	m_isActive = active;
}

void Characters::handleCollision(Characters& item)
{
}

void Characters::handleCollision(Dwarf& item)
{
}

void Characters::handleCollision(Wall& item)
{
}

void Characters::handleCollision(Gift& item)
{
}
