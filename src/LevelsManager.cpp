#include "LevelsManager.h"

#include <filesystem>

#define LEVELS_DIRECTORY "levels"

LevelsManager::LevelsManager()
{
	loadLevelsList();
}

void LevelsManager::loadLevelsList()
{
	for (const auto& entry : std::filesystem::directory_iterator(LEVELS_DIRECTORY))
		m_levelsFiles.emplace_back(entry.path().string());

	m_numOfLevels = m_levelsFiles.size();
}
