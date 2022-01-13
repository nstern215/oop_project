#pragma once

#include "Item.h"

class Controller;
class Warrier;
class King;
class Mage;
class Thief;
class Gift;
class Teleport;
class Dwarf;
class Wall;
class Fire;
class Gate;
class Throne;
class Ork;
class Key;

class BoardItem : public Item {

public:

	BoardItem(Location location = {0, 0}, sf::Vector2f boardLocation = { 0, 0 });
	virtual ~BoardItem();

protected:
};