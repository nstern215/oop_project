#pragma once

#include "Item.h"

class Controller;

class Characters : public Item {

public:

	Characters(Location location = { 0,0 }, sf::Vector2f boardLocation = { 0,0 });
	virtual ~Characters();

	virtual void handleCollision(Item& item) = 0;
	virtual void handleCollision(Key& item) = 0;
	virtual void handleCollision(Ork& item) = 0;
	virtual void handleCollision(Throne& item) = 0;
	virtual void handleCollision(Gate& item) = 0;
	virtual void handleCollision(Fire& item) = 0;
	virtual void handleCollision(Teleport& item) = 0;

	void handleCollision(Characters& item);
	void handleCollision(Dwarf& item);
	void handleCollision(Wall& item);
	void handleCollision(Gift& item);

	virtual void move(sf::Vector2f destination, float deltaTime, Controller& controller);
	void setActive(bool active);
	bool isActive() const;

	Location calcNewLocation(sf::Vector2f step);

protected:

	bool validateMove(sf::Vector2f destination, Controller& controller);

	bool m_isActive;
};
