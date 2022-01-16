#include "Gate.h"

#include "Thief.h"
#include "ResourcesService.h"

Gate::Gate(Location location, sf::Vector2f boardLocation)
	:BoardItem(location, boardLocation)
{
	sf::Texture* t = ResourcesService::instance()->getTexture("gate.png");
	m_rectangle.setTexture(t, true);
}

void Gate::openGate()
{
	m_isActive = false;
}

bool Gate::handleCollision(Item* item)
{
	if (this == item)
		return false;

	return item->handleCollision(this);
}

bool Gate::handleCollision(Thief* item)
{
	if (item->gotKey())
	{
		return true;
	}
	else
	{
		return true;
	}
}