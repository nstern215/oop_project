#pragma once

#include "Characters.h"

class Mage : public Characters {

public:
    Mage(Location location = { 0,0 }, sf::Vector2f boardLocation = {0,0});

    bool handleCollision(Characters* item) override;

private:

	void putOutFire();

};