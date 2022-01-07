#pragma once

#include "Characters.h"

class Thief : public Characters {

public:

	Thief(Location location = { 0,0 });
	~Thief();

	void handleCollision(Item* item) override;
	void handleCollision(Key* item) override;
	void handleCollision(Ork* item) override;
	void handleCollision(Throne* item) override;
	void handleCollision(Gate* item) override;
	void handleCollision(Fire* item) override;
	void handleCollision(Teleport* item) override;
	void handleCollision(Characters* item) override;
	void handleCollision(Dwarf* item) override;
	void handleCollision(Wall* item) override;
	void handleCollision(Gift* item) override;


private:

	void collectKey(Location& location);

	bool m_key;

};