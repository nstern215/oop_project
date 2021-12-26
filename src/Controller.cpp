#include <SFML/Graphics.hpp>
#include <fstream>
#include <filesystem>
#include <iostream>
#include "Controller.h"

#define BOARD_FILE_NAME "Board.txt"
#define FONT_PATH "C:/Windows/Fonts/Arial.ttf"

Controller::Controller()
{
	m_itemInfo = new ItemInfo();
	m_itemInfo->m_texture = nullptr;
	m_itemInfo->m_itemData = " ";

	loadTextures();

	if (!std::filesystem::exists(BOARD_FILE_NAME))
		setNewBoard();
	else
		loadBoardFile();

	m_menu.init(*this);
}

Controller::~Controller()
{
	delete m_itemInfo;
}

void Controller::run()
{
	auto window = sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Board Editor");

	m_board.setPosition({ 0,150 });

	auto font = sf::Font();
	font.loadFromFile(FONT_PATH);
	sf::Text mode(std::to_string(0), font);
	mode.setFillColor(sf::Color::White);
	mode.setPosition(20, 85);

	while (window.isOpen())
	{
		mode.setString(getInfoString());

		window.clear();
		m_board.draw(window);
		window.draw(mode);
		m_menu.draw(window);
		window.display();

		if (auto event = sf::Event{}; window.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonReleased:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					if (m_board.getGlobalBound().contains(window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y })))
					{
						m_board.onMouseClick(event, window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }), *this);
					}
					else if (m_menu.getGlobalBound().contains(window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y })))
					{
						m_menu.onMouseClick(event, window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }), *this);
					}
				}
			}
		}
	}
}