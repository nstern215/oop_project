#pragma once

#include "Item.h"

class BoardItem : public Item {

public:

	BoardItem(ItemInfo* itemInfo = nullptr, Location location(0, 0), float positionOffsetX = 0, float positionOffsetY = 0);

protected:

private:

};