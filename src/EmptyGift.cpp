#include "EmptyGift.h"

EmptyGift::EmptyGift(Location location, sf::Vector2f boardLocation)
	:Gift(location, boardLocation)
{}

EmptyGift::~EmptyGift()
{}

bool EmptyGift::handleCollision(Characters& item)
{

	return true;
}