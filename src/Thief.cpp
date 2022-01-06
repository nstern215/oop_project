#include "Thief.h"

Thief::Thief(Location location)
	:Characters(location)
{
}

Thief::~Thief()
{
}

void Thief::handleCollision(Item& item){}

void Thief::handleCollision(Key& item){}

void Thief::handleCollision(Ork& item){}

void Thief::handleCollision(Throne& item){}

void Thief::handleCollision(Gate& item){}

void Thief::handleCollision(Fire& item){}

void Thief::handleCollision(Teleport& item){}

void Thief::handleCollision(Characters& item){}

void Thief::handleCollision(Dwarf& item){}

void Thief::handleCollision(Wall& item){}

void Thief::handleCollision(Gift& item){}

void Thief::collectKey(Location& location){}
