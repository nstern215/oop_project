#include "Menu.h"

#define ITEM_WIDTH 80
#define SPACE 10

Menu::Menu(sf::Vector2f position):
	m_menuPosition(position)
{}

void Menu::drawMenu(sf::RenderWindow& window)
{
	for (auto& item : m_items)
		item.draw(window);
}

void Menu::addMenuItem(std::string texture, void (Controller::*onClick)())
{
	sf::Vector2f itemPosition((ITEM_WIDTH + SPACE) * m_items.size(), 0);
	itemPosition += m_menuPosition;
	
	m_items.emplace_back(itemPosition, onClick, texture);
}

void Menu::setPosition(sf::Vector2f position)
{
	m_menuPosition = position;
}

void Menu::containsAndClick(sf::Vector2f clickedPoint, Controller& controller)
{
	for (auto& item : m_items)
		item.containsAndClick(clickedPoint, controller);
}
