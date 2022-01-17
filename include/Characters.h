#pragma once

#include "Item.h"

class Controller;

class Characters : public Item {

public:

	Characters(Location location = {0,0}, sf::Vector2f boardLocation = { 0,0 });
    virtual ~Characters();


	virtual void move(sf::Vector2f destination, float deltaTime, Controller& controller);
	virtual void setActive(bool active);
	
    Location calcNewLocation(sf::Vector2f step) const;

	virtual void draw(sf::RenderWindow& window);

protected:

	bool validateMove(Location& position, sf::Vector2f destination, Controller& controller);

	bool m_isActive;
};
