#include "Fire.h"

#include <iostream>

#include "ResourcesService.h"

Fire::Fire(Location location, sf::Vector2f boardLocation)
    :BoardItem(location, boardLocation)
{
    sf::Texture* t = ResourcesService::instance()->getTexture("fire.png");

    //sf::Texture* t = new sf::Texture();
    //t->loadFromFile("crown.png");

    m_rectangle.setTexture(t, true);
}

Fire::~Fire()
{
}

bool Fire::handleCollision(Item* item)
{
    return item->handleCollision(this);
}

bool Fire::handleCollision(King* item)
{
    return false;
}

bool Fire::handleCollision(Warrier* item)
{
    return false;
}

bool Fire::handleCollision(Thief* item)
{
    return false;
}

bool Fire::handleCollision(Mage* item)
{
    this->putOutFire();

    return true;
}

bool Fire::handleCollision(Dwarf* item)
{
    return false;
}

void Fire::putOutFire()
{
}
