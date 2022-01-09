#pragma once

#include <vector>

//class Characters;
//class BoardItem;
#include <SFML/Graphics.hpp>


#include "BoardItem.h"
#include "Characters.h"

class Controller{

public:
	Controller();
	~Controller() = default;

	void run();
	Item* getItem(const Location l);
	sf::Vector2u getBoardSize();

	/*void takeAction(const std::string& command);
	void addTeleport(const int& col, const int& row);
	void addCharacters(const std::string& character);
	void removeTeleport(const int& col, const int& row);

	int getMode();*/
	/*sf::Texture* getTexture(std::string textureName);

	char convertItemToChar(std::string item) const;
	
	std::string convertChatToItem(char c) const;*/

private:

	sf::Vector2f getMovingDirection();
	void buildBoard(int col, int row);

	//void save();
	//std::string getInfoString() const;
	//void setNewBoard();
	//void loadTextures();
	/*void loadBoardFile();
	void getBoardInfo(const std::string line);*/

	std::vector<sf::Vector2i> m_teleports;
	std::vector<Characters> m_characters;
	std::vector<Dwarf> m_dwarfs;
	std::vector<sf::Texture*> m_textures;
  
	sf::RenderWindow m_window;
	sf::RectangleShape m_boardBorder;
	sf::Color m_bgColor;

	unsigned int m_windowWidth;
	unsigned int m_windowHeight;

	//------------------------------------------
	std::vector<BoardItem*> boardItems;
	std::vector<Characters*> characters;
	std::vector<Dwarf*> dwarfs;
};

bool operator==(const Location& a, const Location& b);
bool operator!=(const Location& a, const Location& b);