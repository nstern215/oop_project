#include "LevelsManager.h"

#include <filesystem>
#include <fstream>
#include <iostream>

#include "Dwarf.h"
#include "Fire.h"
#include "Gate.h"
#include "King.h"
#include "Mage.h"
#include "Ork.h"
#include "Dwarf.h"
#include "Teleport.h"
#include "Thief.h"
#include "Throne.h"
#include "Wall.h"
#include "Warrier.h"

#define LEVELS_DIRECTORY "levels\\levels"

LevelsManager* LevelsManager::m_instance = nullptr;

LevelsManager::LevelsManager()
{
	loadLevelsList();
}

LevelsManager::~LevelsManager()
{
	delete m_instance;
}

LevelsManager* LevelsManager::instance()
{
	if (m_instance == nullptr)
		m_instance = new LevelsManager();

	return m_instance;
}

void LevelsManager::loadLevelsList()
{
	for (const auto& entry : std::filesystem::directory_iterator(LEVELS_DIRECTORY))
		m_levelsFiles.emplace_back(entry.path().string());

	m_numOfLevels = m_levelsFiles.size();
}

int LevelsManager::getNumOfLevels() const
{
	return m_numOfLevels;
}

std::unique_ptr<LevelData> LevelsManager::loadLevel(int levelNum)
{
	auto levelData = std::make_unique<LevelData>();

	std::ifstream levelFile;
	levelFile.open(m_levelsFiles[levelNum]);

	if (!levelFile.is_open())
	{
		std::cerr << "Failed to load level file " << m_levelsFiles[levelNum] << std::endl;
		exit(EXIT_FAILURE);
	}

	std::vector<std::string> board;
	std::vector<std::string> teleportVector;

	int rowCount = 0;
	int teleportsCount = 0;

	while (!levelFile.eof())
	{
		std::string line;
		levelFile >> line;

		if (line.empty())
			continue;

		if (line[0] == '-')
			break;

		for (int i = 0; i < line.length(); i++)
		{
			Location location = { rowCount, i };

			switch (line[i])
			{
			case '=':
				levelData->m_boardItems.push_back(std::make_unique<Wall>(location));
				break;
			case '*':
				levelData->m_boardItems.push_back(std::make_unique<Fire>(location));
				break;
			case '#':
				levelData->m_boardItems.push_back(std::make_unique<Gate>(location));
				break;
			case '!':
				levelData->m_boardItems.push_back(std::make_unique<Ork>(location));
				break;
			case '@':
				levelData->m_boardItems.push_back(std::make_unique<Throne>(location));
				break;
			case 'K':
				levelData->m_characters.push_back(std::make_unique<King>(location));
				break;
			case 'M':
				levelData->m_characters.push_back(std::make_unique<Mage>(location));
				break;
			case 'T':
				levelData->m_characters.push_back(std::make_unique<Thief>(location));
				break;
			case 'W':
				levelData->m_characters.push_back(std::make_unique<Warrier>(location));
				break;
			case '^':
				levelData->m_characters.push_back(std::make_unique<Dwarf>(location));
				break;
			case 'X':
				teleportsCount++;
				break;
			}
		}


		board.emplace_back(line);
		rowCount++;
	}

	//read teleport pairs
	for (int i = 0; i < teleportsCount / 2 && !levelFile.eof(); i++)
	{
		int sourceRow;
		int sourceCol;
		int pairRow;
		int pairCol;

		levelFile >> sourceRow >> sourceCol >> pairRow >> pairCol;

		Location source = { sourceRow, sourceCol };
		Location pair = { pairRow, pairCol };

		levelData->m_boardItems.push_back(std::make_unique<Teleport>(source, pair));
		levelData->m_boardItems.push_back(std::make_unique<Teleport>(pair, source));
	}

	if (!levelFile.eof())
	{
		std::string line;
		levelFile >> line;

		if (line == "TIME")
		{
			int seconds;
			levelFile >> seconds;
			levelData->m_timeLimit = seconds;
		}
	}
	
	levelData->m_rows = board.size();
	levelData->m_cols = board[0].size();

	return levelData;
}
