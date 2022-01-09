#pragma once

#include "Characters.h"

class King : public Characters {

public:

	King(Location location = {0,0}, sf::Vector2f boardLocation = {0,0});
    ~King();
	
	void sitInThrone();
	bool isAtThrone();

	bool gotToEdge();
	bool handleCollision(Item* item) override;
	bool handleCollision(Key* item) override;
	bool handleCollision(Ork* item) override;
	bool handleCollision(Throne* item) override;
	bool handleCollision(Gate* item) override;
	bool handleCollision(Fire* item) override;
	bool handleCollision(Characters* item) override;
	bool handleCollision(Dwarf* item) override;
	bool handleCollision(Wall* item) override;

	bool handleCollision(Teleport* item) override;
	bool handleCollision(Gift* item) override;

private:

	bool gotToThrone(Location& location);

	bool m_throne;

};