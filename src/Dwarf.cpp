#include "Dwarf.h"
#include "ResourcesService.h"

Dwarf::Dwarf(int go, Location location)
	:Characters(location)
{
	setDirection(go);

	setActive(true);

	m_rectangle.setFillColor(sf::Color::White);

	sf::Texture* t = ResourcesService::instance()->getTexture("ork.png");

	//sf::Texture* t = new sf::Texture();
	//t->loadFromFile("crown.png");

	m_rectangle.setTexture(t, true);
}

Dwarf::~Dwarf()
{
}

void Dwarf::setDirection(const int& direction)
{
	if (direction == UP)
	{
		m_direction = { -1,0 };
	}
	if (direction == DOWN)
	{
		m_direction = { 1,0 };
	}
	if (direction == LEFT)
	{
		m_direction = { 0,-1 };
	}
	if (direction == RIGHT)
	{
		m_direction = { 0,1 };
	}
}

sf::Vector2f Dwarf::getDirection()
{
	return m_direction;
}

void Dwarf::handleCollision(Item& item)
{
	if (&item == this) return;
	
	item.handleCollision(*this);
}

void Dwarf::handleCollision(Wall& item)
{
	m_direction.x = -m_direction.x;
	m_direction.y = -m_direction.y;
}

void Dwarf::handleCollision(Key& item)
{
}

void Dwarf::handleCollision(Ork& item)
{
}

void Dwarf::handleCollision(Throne& item)
{
}

void Dwarf::handleCollision(Gate& item)
{
}

void Dwarf::handleCollision(Fire& item)
{
}

void Dwarf::handleCollision(Teleport& item)
{
}

void Dwarf::handleCollision(Characters& item)
{
}

void Dwarf::handleCollision(Dwarf& item)
{
}

void Dwarf::handleCollision(Gift& item)
{
}
