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
    return false;
}

bool Fire::handleCollision(Characters* item)
{
    std::cout << "collision" << std::endl;
    return item->handleCollision(this);
}

bool Fire::handleCollision(Dwarf* item)
{
    return false;
}
