#pragma once

#include "Characters.h"

class Thief : public Characters {

public:

	Thief(Location location = { 0,0 }, sf::Vector2f boardLocation = { 0,0 });

	bool gotKey();

	bool handleCollision(Item* item);
	bool handleCollision(Key* item)override;
	bool handleCollision(Gate* item)override;

private:

	void collectKey();

	bool m_key;

};