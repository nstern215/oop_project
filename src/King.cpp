#include "King.h"
#include "ResourcesService.h"

King::King(Location location, sf::Vector2f boardLocation)
	:Characters(location, boardLocation)
{
	m_throne = false;

	sf::Texture* t = ResourcesService::instance()->getTexture("crown.png");

	//sf::Texture* t = new sf::Texture();
	//t->loadFromFile("crown.png");
	
	m_rectangle.setTexture(t, true);
}

King::~King()
{
	
}

void King::sitInThrone()
{
	m_throne == true;
}

bool King::isAtThrone()
{
	return m_throne;
}

bool King::gotToThrone(Location& location)
{
	return m_throne;
}

bool King::gotToEdge()
{
	return false;
}

bool King::handleCollision(Item* item)
{
	if (item == this)
		return false;

	return item->handleCollision(this);
}

bool King::handleCollision(Throne* item)
{
	this->sitInThrone();

	return true;
}

bool King::handleCollision(Teleport* item)
{
	return true;
}

bool King::handleCollision(Gift* item) 
{
	return true;
}

bool King::handleCollision(Key* item)
{
	return true;
}

bool King::handleCollision(Ork* item)
{
	return false;
}

bool King::handleCollision(Gate* item)
{
	return false;
}

bool King::handleCollision(Fire* item)
{
	return false;
}

bool King::handleCollision(Characters* item)
{
	return false;
}

bool King::handleCollision(Dwarf* item)
{
	return false;
}

bool King::handleCollision(Wall* item)
{
	return false;
}