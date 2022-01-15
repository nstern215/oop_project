#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "BoardItem.h"
#include "Characters.h"
#include "Clock.h"
#include "Dwarf.h"
#include "GameMode.h"
#include "LevelData.h"
#include "Menu.h"

class Controller{

public:
	Controller();
	~Controller() = default;

	void run();
	Item* getItem(const Location l);
	sf::Vector2u getBoardSize() const;
	sf::Vector2u getLevelBoardSize() const;
	
	/*void takeAction(const std::string& command);
	void addTeleport(const int& col, const int& row);
	void addCharacters(const std::string& character);
	void removeTeleport(const int& col, const int& row);

	int getMode();*/
	/*sf::Texture* getTexture(std::string textureName);

	char convertItemToChar(std::string item) const;
	
	std::string convertChatToItem(char c) const;*/

private:

	static sf::Vector2f getMovingDirection();
	void buildBoard();
	void initalizeLevel();
	void initializeMenu();
	void updateStatusLine();

	void drawLevel();
	void drawWelcomeView();
	void drawTutorialView();
	void drawLevelCompletedView();
	void drawWinGameView();
	void resumeGame();
	void loadNextLevel();
	
	void exitGame();
	void tutorial();
	void resetLevel();
	
	//void save();
	//std::string getInfoString() const;
	//void setNewBoard();
	//void loadTextures();
	/*void loadBoardFile();
	void getBoardInfo(const std::string line);*/
	/*std::vector<sf::Vector2i> m_teleports;
	std::vector<Characters> m_characters;
	std::vector<Dwarf> m_dwarfs;*/

	std::vector<sf::Texture*> m_textures;

	Clock m_gameClock;
  
	sf::RenderWindow m_window;
	sf::RectangleShape m_boardBorder;
	sf::Color m_bgColor;
	sf::Text m_statusLine;
	
	int m_currentLevelNum;
	int m_activeCharacter;

	std::unique_ptr<LevelData> m_currentLevel;

	float m_currentLevelTime;
	
	Menu m_menu;
	GameMode m_mode;
	
	//------------------------------------------
	std::vector<Dwarf*> dwarfs;

};

bool operator==(const Location& a, const Location& b);
bool operator!=(const Location& a, const Location& b);