#include "Fire.h"

#include <iostream>

#include "ResourcesService.h"

Fire::Fire(Location location, sf::Vector2f boardLocation)
    :BoardItem(location, boardLocation)
{
    sf::Texture* t = ResourcesService::instance()->getTexture("fire.png");
    m_rectangle.setTexture(t, true);
}


void Fire::putOutFire()
{
    m_isActive = false;
}

bool Fire::handleCollision(Item* item)
{
    if (this == item)
        return false;

    return item->handleCollision(this);
}

bool Fire::handleCollision(Mage* item)
{
    this->putOutFire();
    return true;
}