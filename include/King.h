#pragma once

#include "Characters.h"

class King : public Characters {

public:

	King(Location location = {0,0}, sf::Vector2f boardLocation = {0,0});

	bool handleCollision(Item* item);
	bool handleCollision(Throne* item)override;
	
private:

	void sitInThrone();
	bool isAtThrone();
	
	bool m_throne;

};