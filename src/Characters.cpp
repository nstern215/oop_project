#include "Characters.h"

#include <iostream>

#include "Wall.h"

#include "Controller.h"

Characters::Characters(Location location, sf::Vector2f boardLocation) :
	Item(location, boardLocation),
	m_isActive(false)
{
}

Characters::~Characters()
{
	m_rectangle.setOutlineThickness(5);
	m_rectangle.setOutlineColor(sf::Color::Black);

	m_rectangle.setFillColor(sf::Color(100, 100, 100));
}

void Characters::move(sf::Vector2f destination, float deltaTime, Controller& controller)
{
	if (!m_isActive)
		return;

	const auto destLocation = calcNewLocation(destination);

	//if (destLocation != m_location)
	if (!validateMove(destination, controller))
		return;

	m_location = destLocation;

	std::cout << "Location " << m_location.m_col << ":" << m_location.m_row << std::endl;

	const sf::Vector2f dest = destination * deltaTime * m_speedPerSecond;
	m_rectangle.move(dest);
}

Location Characters::calcNewLocation(sf::Vector2f direction)
{
	sf::Vector2f size = m_rectangle.getSize();
	size /= 2.f;
	sf::Vector2f center = m_rectangle.getPosition();
	center += size;

	center += direction;

	Location destination = m_location;

	sf::RectangleShape origin(m_rectangle);
	sf::Vector2f originPosition = m_boardLocation;
	originPosition.x += m_location.m_col * size.x * 2.f;
	originPosition.y += m_location.m_row * size.y * 2.f;

	origin.setPosition(originPosition);

	const sf::FloatRect originBound = origin.getGlobalBounds();

	if (originBound.contains(center))
		return destination;

	if (center.x < originBound.left)
		destination.m_col -= 1;
	else if (center.x > (originBound.left + originBound.width))
		destination.m_col += 1;
	else if (center.y < originBound.top)
		destination.m_row -= 1;
	else
		destination.m_row += 1;

	return destination;
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
		/*m_rectangle.setFillColor(sf::Color::White);*/
		m_rectangle.setFillColor(sf::Color(100, 100, 100));

	m_isActive = active;
}

bool Characters::validateMove(sf::Vector2f destination, Controller& controller)
{
	if (destination.x == 0 && destination.y == 0)
		return false;

	Location destLocation = { m_location.m_row, m_location.m_col };

	if (destination.x != 0)
	{
		if (destination.x < 0)
			destLocation.m_col -= 1;
		else
			destLocation.m_col += 1;
	}
	else
	{
		if (destination.y < 0)
			destLocation.m_row -= 1;
		else
			destLocation.m_row += 1;
	}

	Item* destItem = controller.getItem(destLocation);

	if (!destItem)
		return true;

	if (dynamic_cast<Characters*>(destItem) || dynamic_cast<Wall*>(destItem))
		return false;

	return true;
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
