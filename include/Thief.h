#pragma once

#include "Characters.h"

class Thief : public Characters {

public:

	Thief(Location location = { 0,0 });
	~Thief();

	bool gotKey();

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

	void collectKey();

	bool m_key;

};