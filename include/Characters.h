#pragma once

#include "Item.h"

class Characters : public Item {

public:

	Characters(ItemInfo* itemInfo = nullptr, Location location(0, 0), float positionOffsetX = 0, float positionOffsetY = 0);

	//virtual void move(sf::Vector2f destination);

	//virtual draw(sf::RenderWindow& window);
	//
	//void setIsActive();

protected:

	bool m_isActive;
};