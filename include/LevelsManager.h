#pragma once

#include <memory>
#include <string>
#include <vector>

#include "LevelData.h"

class LevelsManager
{
public:
	~LevelsManager() = default;

	static LevelsManager* instance();
	
	int getNumOfLevels() const;
	std::unique_ptr<LevelData> loadLevel(int levelNum);

private:
	LevelsManager();

	LevelsManager& operator=(const LevelsManager&) = default;

	static LevelsManager* m_instance;
	
	void loadLevelsList();
	
	std::vector<std::string> m_levelsFiles;
	unsigned int m_numOfLevels;
	std::string m_currentPath;
};
