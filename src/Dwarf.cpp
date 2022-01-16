#include "Dwarf.h"
#include "ResourcesService.h"

Dwarf::Dwarf(Location location, sf::Vector2f boardLocation):
	Characters(location, boardLocation)
{
	m_go = rand() % 4; 

	setDirection(m_go);

	m_isActive = true;

	sf::Texture* t = ResourcesService::instance()->getTexture("dwarf.png");

	m_rectangle.setTexture(t, true);
}

void Dwarf::setActive(bool active)
{}

void Dwarf::draw(sf::RenderWindow& window)
{
	Item::draw(window);
}

void Dwarf::setDirection(const int& direction)
{
	if(direction == UP)
	{
		m_direction = { -1,0 };
	}
	if(direction == DOWN)
	{
		m_direction = { 1,0 };
	}
	if(direction == LEFT)
	{
		m_direction = { 0,-1 };
	}
	if(direction == RIGHT)
	{
		m_direction = { 0,1 };
	}
}

void Dwarf::move(sf::Vector2f destination, float deltaTime, Controller& controller)
{
	Characters::move(getDirection(), deltaTime, controller);
}


void Dwarf::changeDirection()
{
	m_direction.x = -m_direction.x;
	m_direction.y = -m_direction.y;
}

sf::Vector2f Dwarf::getDirection() const
{
	return m_direction;
}

bool Dwarf::handleCollision(Item* item)
{
	if (this == item)
		return false;

	return item->handleCollision(this);
}

bool Dwarf::handleCollision(Fire* item)
{
	this->changeDirection();
	return false;
}

bool Dwarf::handleCollision(Gate* item)
{
	this->changeDirection();
	return false;
}

bool Dwarf::handleCollision(Ork* item)
{
	this->changeDirection();
	return false;
}

bool Dwarf::handleCollision(Throne* item)
{
	this->changeDirection();
	return false;
}

bool Dwarf::handleCollision(King* item)
{
	this->changeDirection();
	return false;
}

bool Dwarf::handleCollision(Thief* item)
{
	this->changeDirection();
	return false;
}

bool Dwarf::handleCollision(Mage* item)
{
	this->changeDirection();
	return false;
}

bool Dwarf::handleCollision(Warrier* item)
{
	this->changeDirection();
	return false;
}

bool Dwarf::handleCollision(Dwarf* item)
{
	this->changeDirection();
	return false;
}

bool Dwarf::handleCollision(Wall* item)
{
	this->changeDirection();
	return false;
}