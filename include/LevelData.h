#pragma once

#include <memory>
#include <string>

#include "Location.h"
#include "GiftData.h"

#include <vector>


#include "BoardItem.h"
#include "Characters.h"

struct LevelData {
	std::vector<std::string> m_boardLines;
	std::vector<std::unique_ptr<Characters>> m_characters;
	std::vector<std::unique_ptr<BoardItem>> m_boardItems;
	std::vector<Location> m_teleports;
	std::vector<GiftData> m_giftData;

	unsigned int m_cols;
	unsigned int m_rows;
};
