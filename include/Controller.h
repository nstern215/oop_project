#pragma once

#include <vector>

//class Characters;
//class BoardItem;
//class Dwarf;
#include <SFML/Graphics.hpp>


#include "BoardItem.h"
#include "Characters.h"
#include "Dwarf.h"

class Controller{

public:
	Controller();
	~Controller() = default;

	void run();
	void takeAction(const std::string& command);
	void addTeleport(const int& col, const int& row);
	void addCharacters(const std::string& character);
	void removeTeleport(const int& col, const int& row);

	int getMode();
	sf::Texture* getTexture(std::string textureName);

	char convertItemToChar(std::string item) const;
	
	std::string convertChatToItem(char c) const;

	Item* getItem(Location l);

private:
	sf::Vector2f getMovingDirection();
	void buildBoard(int col, int row);
	
	void loadBoardFile();
	void getBoardInfo(const std::string line);
	void save();
	std::string getInfoString() const;
	void setNewBoard();
	void loadTextures();

	std::vector<sf::Vector2i> m_teleports;
	std::vector<Characters> m_characters;
	std::vector<Dwarf> m_dwarfs;
	std::vector<sf::Texture*> m_textures;


	//Menu m_menu;
	//Board m_board;
  
	sf::RenderWindow m_window;
	sf::RectangleShape m_boardBorder;
	sf::Color m_bgColor;

	unsigned int m_windowWidth;
	unsigned int m_windowHeight;

	//------------------------------------------
	std::vector<BoardItem*> boardItems;
	std::vector<Characters*> characters;
};
