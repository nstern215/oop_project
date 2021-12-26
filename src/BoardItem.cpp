#include "BoardItems.h"
#include "..\include\BoardItem.h"

BoardItem::BoardItem(ItemInfo* itemInfo, Location location, float positionOffsetX, float positionOffsetY)
	:Item(itemInfo, location, positionOffsetX, positionOffsetY)
{
}
