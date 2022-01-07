#include "Warrier.h"

Warrier::Warrier(Location location)
	:Characters(location)
{
}

Warrier::~Warrier()
{
}

void Warrier::handleCollision(Item* item)
{
}

void Warrier::handleCollision(Key* item){}

void Warrier::handleCollision(Ork* item){}

void Warrier::handleCollision(Throne* item){}

void Warrier::handleCollision(Gate* item){}

void Warrier::handleCollision(Fire* item){}

void Warrier::handleCollision(Teleport* item){}

void Warrier::handleCollision(Characters* item){}

void Warrier::handleCollision(Dwarf* item){}

void Warrier::handleCollision(Wall* item){}

void Warrier::handleCollision(Gift* item){}


