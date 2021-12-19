#pragma once

#include "Location.h"
#include "GiftData.h"

#include <vector>

struct LevelData {

	std::vector<std::string> m_boardLines;
	
	std::vector<Location> m_teleports;

	std::vector<GiftData> m_giftData;

};