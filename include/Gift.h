#pragma once

#include "BoardItem.h"
#include "GiftType.h"

class Gift : public BoardItem {

public:

	Gift(Location location = { 0, 0 }, sf::Vector2f boardLocation = { 0, 0 });
	virtual ~Gift();

	bool handleCollision(Item& item);
	bool handleCollision(Dwarf& item);
	virtual bool handleCollision(Characters& item)= 0;

	int useGift();


protected:
	int m_giftNum;
	bool m_available;
};