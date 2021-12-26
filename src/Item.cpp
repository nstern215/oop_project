#include "Item.h"
#include "..\include\Item.h"

Item::Item(ItemInfo* itemInfo, Location location, float positionOffsetX, float positionOffsetY)
	:m_itemInfo(itemInfo),
	m_location(location)
{
	setPosition(positionOffsetX, positionOffsetY);

	if (!m_itemInfo)
	{
		m_itemInfo = new ItemInfo();
		m_itemInfo->m_texture = nullptr;
		m_itemInfo->m_itemData = " ";
	}
}

Item::~Item()
{
	delete m_itemInfo;
}

