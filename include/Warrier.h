#pragma once

#include "Characters.h"

class Warrier : public Characters {

public:


	Warrier(Location location = { 0,0 }, sf::Vector2f boardLocation = { 0,0 });

	bool handleCollision(Characters* item) override;

	//bool handleCollision(Key* item);
	//bool handleCollision(Ork* item);
	//bool handleCollision(Throne* item) override;
	//bool handleCollision(Gate* item) override;
	//bool handleCollision(Fire* item) override;
	//bool handleCollision(King* item) override;
	//bool handleCollision(Warrier* item) override;
	//bool handleCollision(Mage* item) override;
	//bool handleCollision(Thief* item) override;
	//bool handleCollision(Dwarf* item) override;
	//bool handleCollision(Wall* item) override;
	//bool handleCollision(Teleport* item) override;
	//bool handleCollision(Gift* item) override;

private:

};