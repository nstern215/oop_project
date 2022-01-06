#pragma once

#include "Characters.h"

class King : public Characters {

public:

	King(Location location = {0,0}, sf::Vector2f boardLocation = {0,0});
    ~King();
	
    virtual void handleCollision(Item& item);
    virtual void handleCollision(Key& item);
    virtual void handleCollision(Ork& item);
    virtual void handleCollision(Throne& item);
    virtual void handleCollision(Gate& item);
    virtual void handleCollision(Fire& item);
    virtual void handleCollision(Teleport& item);

private:

	bool gotToThrone(Location& location);

	bool m_throne;

};