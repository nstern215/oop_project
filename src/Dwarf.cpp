#include "Dwarf.h"
#include "ResourcesService.h"

Dwarf::Dwarf(Location location, sf::Vector2f boardLocation)
	:Characters(location, boardLocation)
{
	m_go = rand() % 4;

	setDirection(m_go);

	setActive(true);

	m_rectangle.setFillColor(sf::Color::White);

	sf::Texture* t = ResourcesService::instance()->getTexture("dwarf.png");

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

void Dwarf::chengeDirection()
{
	m_direction.x = -m_direction.x;
	m_direction.y = -m_direction.y;
}

sf::Vector2f Dwarf::getDirection()
{
	return m_direction;
}

void Dwarf::handleCollision(Item* item)
{
	if (item == this)
		return;

	item->handleCollision(this);
}

void Dwarf::handleCollision(Wall* item)
{
	this->chengeDirection();
}

void Dwarf::handleCollision(Ork* item) 
{
	this->chengeDirection();
}

void Dwarf::handleCollision(Throne* item) 
{
	this->chengeDirection();
}

void Dwarf::handleCollision(Fire* item) 
{
	this->chengeDirection();
}

void Dwarf::handleCollision(Key* item){}

void Dwarf::handleCollision(Gate* item){}

void Dwarf::handleCollision(Teleport* item){}

void Dwarf::handleCollision(Characters* item){}

void Dwarf::handleCollision(Dwarf* item){}

void Dwarf::handleCollision(Gift* item){}