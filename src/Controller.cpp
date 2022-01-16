#include <SFML/Graphics.hpp>
#include <memory>

#include <iostream>

#include "Controller.h"
#include "Clock.h"
#include "BoardItem.h"
#include "Characters.h"
#include "King.h"
#include "LevelsManager.h"
#include "Mage.h"
#include "Dwarf.h"
#include "Key.h"
#include "ResourcesService.h"

Controller::Controller() :
	m_window(sf::VideoMode(1600, 900), "Save the King", sf::Style::Default),
	//m_bgColor(39, 72, 245, 0.8),
	m_currentLevelNum(-1),
	m_isActiveCharacter(0),
	m_mode(GAME)
{
	initializeMenu();
	buildBoard();

	m_statusLine.setFont(*(ResourcesService::instance()->getFont("Hypeblox.ttf")));
	m_statusLine.setFillColor(sf::Color::Black);
	m_statusLine.setCharacterSize(50);
	m_statusLine.setPosition({ 10,10 });
}

void Controller::run()
{
	auto winSize = m_window.getSize();
	sf::RectangleShape background({static_cast<float>(winSize.x), static_cast<float>(winSize.y) });
	background.setTexture(ResourcesService::instance()->getTexture("background.jpg"));
	
	m_window.setFramerateLimit(60);

	while (m_window.isOpen())
	{
		m_window.clear(m_bgColor);
		m_window.draw(background);
		
		switch (m_mode)
		{
		case WELCOME:
			drawWelcomeView();
			break;
		case GAME:
			drawLevel();
			break;
		case TUTORIAL:
			drawTutorialView();
			break;
		case WIN:
			drawWinGameView();
			break;
		case LEVEL_COMPLETED:
			drawLevelCompletedView();
			break;
		}

		/*for (auto& item : m_currentLevel->m_boardItems)
			item->draw(m_window);

		for (auto& item : m_currentLevel->m_characters)
			if (!item->isActive())
				item->draw(m_window);

		m_currentLevel->m_characters[m_isActiveCharacter]->draw(m_window);*/

		m_window.display();

		for (auto event = sf::Event{}; m_window.pollEvent(event); )
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;
			case sf::Event::KeyPressed:
				if (m_mode != GAME)
				{
					switch (m_mode)
					{
					case WIN:
						m_window.close();
						break;
					case LEVEL_COMPLETED:
						loadNextLevel();
						break;
						default:
							resumeGame();
							break;
					}
				}
				else if (event.key.code == sf::Keyboard::Key::P)
				{
					m_currentLevel->m_characters[m_isActiveCharacter]->setActive(false);
					m_isActiveCharacter = (m_isActiveCharacter + 1) % m_currentLevel->m_characters.size();
					m_currentLevel->m_characters[m_isActiveCharacter]->setActive(true);
				}
				break;
			case sf::Event::MouseButtonReleased:
				m_menu.containsAndClick(m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }), *this);
				break;
			}
		}

		if (m_mode == GAME)
		{
			std::erase_if(m_currentLevel->m_boardItems, [](std::unique_ptr<BoardItem>& item)
				{
					return !item->isActive();
				});
			
			const auto moveDirection = getMovingDirection();
			const auto deltaTime = m_gameClock.updateTime();

		/*	for (auto& d : dwarfs)
				d->move(d->getDirection(), deltaTime, *this);*/

			if (moveDirection.x != 0 || moveDirection.y != 0)
				for (auto& c : m_currentLevel->m_characters)
					c->move(moveDirection, deltaTime, *this);

			updateStatusLine();
		}
	}
}

sf::Vector2f Controller::getMovingDirection()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		return { 0, -1 };
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		return { 0, 1 };
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		return { 1, 0 };
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		return { -1, 0 };
	return { 0,0 };
}

Item* Controller::getItem(const Location l)
{
	for (auto& item : m_currentLevel->m_characters)
		if (item->getLocation() == l)
			return item.get();

	for (auto& item : m_currentLevel->m_boardItems)
		if (item->getLocation() == l)
			return item.get();

	return nullptr;
}

sf::Vector2u Controller::getBoardSize() const
{
	const sf::Vector2u boardSize((m_window.getSize().x) / 100, (m_window.getSize().y) / 100);
	return boardSize;
}

void Controller::buildBoard()
{
	const auto windowSize = m_window.getSize();

	/*const sf::Vector2f boardSize(static_cast<float>(windowSize.x) * 0.9f, static_cast<float>(windowSize.y) * 0.9f);*/
	const sf::Vector2f boardSize(static_cast<float>(windowSize.y) * 0.9f, static_cast<float>(windowSize.y) * 0.9f);

	const sf::Vector2f boardOrigin(static_cast<float>(windowSize.x) * 0.05f, static_cast<float>(windowSize.y) * 0.09f);

	m_boardBorder.setSize(boardSize - sf::Vector2f(3.f, 3.f));
	m_boardBorder.setOutlineThickness(8);
	m_boardBorder.setOutlineColor(sf::Color::Black);
	m_boardBorder.setFillColor(sf::Color(255, 255, 255, 128));
	m_boardBorder.setPosition(boardOrigin);
}

void Controller::initializeLevel()
{
	const float item_width = m_boardBorder.getSize().x / static_cast<float>(m_currentLevel->m_cols);
	const float item_height = m_boardBorder.getSize().y / static_cast<float>(m_currentLevel->m_rows);
	const sf::Vector2f itemSize = { item_width, item_height };

	for (auto& item : m_currentLevel->m_boardItems)
	{
		item->setBoardLocation(m_boardBorder.getPosition());
		item->setSize(itemSize);
		item->setActive(true);
	}

	for (auto& item : m_currentLevel->m_characters)
	{
		item->setBoardLocation(m_boardBorder.getPosition());
		item->setSize(itemSize);
	}

	m_isActiveCharacter = 0;

	m_gameClock.reset();

	if (m_currentLevel->m_timeLimit == 0)
		m_gameClock.setMode(STOPWATCH);
	else
		m_gameClock.setMode(TIMER);

	m_gameClock.reset(m_currentLevel->m_timeLimit);

	m_mode = GAME;
}

void Controller::addKey(const Location& location)
{
	m_currentLevel->m_boardItems.emplace_back(std::make_unique<Key>(location));
}

void Controller::levelComplited()
{
	m_mode = LEVEL_COMPLETED;
}

sf::Vector2u Controller::getLevelBoardSize() const
{
	return { m_currentLevel->m_cols, m_currentLevel->m_rows };
}

void Controller::initializeMenu()
{
	m_menu.setPosition({ m_window.getSize().x / 2.f, 3 });

	m_menu.addMenuItem("crown.png", &Controller::exitGame);
	m_menu.addMenuItem("crown.png", &Controller::resetLevel);
	m_menu.addMenuItem("crown.png", &Controller::tutorial);
}

void Controller::exitGame()
{
	std::cout << "exit" << std::endl;
	m_window.close();
}

void Controller::resetLevel()
{
	m_currentLevel = LevelsManager::instance()->loadLevel(m_currentLevelNum);
	initializeLevel();
	std::cout << "reset" << std::endl;
}

void Controller::tutorial()
{
	m_mode = TUTORIAL;
	m_currentLevelTime = m_gameClock.stopClock();
	std::cout << "tutorial" << std::endl;
}

void Controller::updateStatusLine()
{
	m_statusLine.setString(m_gameClock.toString());
}

void Controller::drawLevel()
{
	if (m_currentLevelNum == -1)
		loadNextLevel();

	updateStatusLine();
	m_window.draw(m_boardBorder);
	m_window.draw(m_statusLine);
	m_menu.drawMenu(m_window);

	for (auto& item : m_currentLevel->m_boardItems)
		item->draw(m_window);

	for (auto& item : m_currentLevel->m_characters)
		if (!item->isActive())
			item->draw(m_window);

	/*for (auto& item : dwarfs)
		item->draw(m_window);*/

	//m_currentLevel->m_characters[m_isActiveCharacter]->draw(m_window);
}

void Controller::drawLevelCompletedView()
{

}

void Controller::drawTutorialView()
{

}

void Controller::drawWelcomeView()
{

}

void Controller::drawWinGameView()
{

}

void Controller::resumeGame()
{
	if (m_mode == WELCOME)
		loadNextLevel();
	else
	{
		m_gameClock.resumeClock(m_currentLevelTime);
		m_mode = GAME;
	}
}

void Controller::loadNextLevel()
{
	if (m_currentLevelNum >= LevelsManager::instance()->getNumOfLevels())
		m_mode = WIN;
	else
	{
		m_currentLevelNum++;
		m_currentLevel = LevelsManager::instance()->loadLevel(m_currentLevelNum);
		initializeLevel();
	}
}

//location operators
bool operator==(const Location& a, const Location& b)
{
	return a.m_row == b.m_row && a.m_col == b.m_col;
}

bool operator!=(const Location& a, const Location& b)
{
	return !(a == b);
}