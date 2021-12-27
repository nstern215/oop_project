#pragma once

#include "Characters.h"

class Mage : public Characters {

public:
    Mage(Location location = { 0,0 });
    ~Mage();

    virtual void handleCollision(Item& item);
    virtual void handleCollision(Key& item);
    virtual void handleCollision(Ork& item);
    virtual void handleCollision(Throne& item);
    virtual void handleCollision(Gate& item);
    virtual void handleCollision(Fire& item);
    virtual void handleCollision(Teleport& item);
protected:

private:

	void putOutFire(Location& locacoin);

};