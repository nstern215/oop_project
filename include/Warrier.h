#pragma once

#include "Characters.h"

class Warrier : public Characters {

public:


	Warrier(Location location = { 0,0 });
	~Warrier();

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

};