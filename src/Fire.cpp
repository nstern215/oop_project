#include "Fire.h"
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
    return false;
}

bool Fire::handleCollision(Dwarf* item)
{
    return false;
}
