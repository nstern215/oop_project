#pragma once

#include "Characters.h"

class Warrier : public Characters {

public:


	Warrier(Location location = { 0,0 }, sf::Vector2f boardLocation = { 0,0 });

	bool handleCollision(Item* item);
	bool handleCollision(Ork* item)override;

private:

};