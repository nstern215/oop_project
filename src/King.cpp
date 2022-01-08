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

void King::handleCollision(Item* item)
{
	if (item == this)
		return;

	item->handleCollision(this);
}

void King::handleCollision(Throne* item)
{
	this->sitInThrone();
}

void King::handleCollision(Teleport* item) 
{

}

void King::handleCollision(Gift* item) {}

void King::handleCollision(Key* item){}

void King::handleCollision(Ork* item){}

void King::handleCollision(Gate* item){}

void King::handleCollision(Fire* item){}

void King::handleCollision(Characters* item){}

void King::handleCollision(Dwarf* item){}

void King::handleCollision(Wall* item){}