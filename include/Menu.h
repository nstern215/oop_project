#pragma once

#include <SFML/Graphics.hpp>
#include "MenuItem.h"

class Controller;

class Menu
{
public:
	Menu(sf::Vector2f position = { 0,0 });
	
	void drawMenu(sf::RenderWindow& window);
	void addMenuItem(std::string texture, void(Controller::*onClick)());
	void setPosition(sf::Vector2f position);
	void containsAndClick(sf::Vector2f clickedPoint, Controller& controller);

private:
	sf::Vector2f m_menuPosition;

	std::vector<MenuItem> m_items;
};
