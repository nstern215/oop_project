#include "King.h"
#include "ResourcesService.h"

King::King(Location location, sf::Vector2f boardLocation)
	:Characters(location, boardLocation)
{
	m_throne = false;

	sf::Texture* t = ResourcesService::instance()->getTexture("crown.png");

	//sf::Texture* t = new sf::Texture();
	//t->loadFromFile("crown.png");
	
	//m_rectangle.setTexture(t, true);
}

King::~King()
{
	
}


bool King::gotToThrone(Location& location)
{
	return m_throne;
}

void King::handleCollision(Fire& item)
{
	
}

void King::handleCollision(Gate& item)
{
	
}

void King::handleCollision(Item& item)
{
	
}

void King::handleCollision(Key& item)
{
	
}

void King::handleCollision(Ork& item)
{
	
}

void King::handleCollision(Teleport& item)
{
	
}

void King::handleCollision(Throne& item)
{
	
}
