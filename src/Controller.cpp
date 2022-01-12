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
#include "ResourcesService.h"

Controller::Controller() :
	m_window(sf::VideoMode(1000, 1000), "Save the King", sf::Style::Default),
	m_bgColor(39, 72, 245, 0.8)
{}

void Controller::run()
{	
	int activeCharacter = 0;

	const int row = 10;
	const int col = 10;

	buildBoard(col, row);

	m_currentLevel = LevelsManager::instance()->loadLevel(0);
	initalizeLevel();

	m_window.setFramerateLimit(120);

	sf::Clock clock;
	
	sf::Vector2f boardPosition = m_boardBorder.getPosition();

	sf::Text statusLine;
	statusLine.setFont(*(ResourcesService::instance()->getFont("Hypeblox.ttf")));
	statusLine.setFillColor(sf::Color::Black);
	statusLine.setCharacterSize(50);
	statusLine.setPosition({ 10,10 });

	m_gameClock.reset();
	statusLine.setString(m_gameClock.toString());

	while (m_window.isOpen())
	{
		m_window.clear(m_bgColor);
		m_window.draw(m_boardBorder);

		m_window.draw(statusLine);

		for (auto& item : m_currentLevel->m_boardItems)
			item->draw(m_window);

		for (auto& item : m_currentLevel->m_characters)
			if (!item->isActive())
				item->draw(m_window);

		for (auto& item : dwarfs)
			item->draw(m_window);

		m_currentLevel->m_characters[activeCharacter]->draw(m_window);

		m_window.display();

		for (auto event = sf::Event{}; m_window.pollEvent(event); )
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Key::P)
				{
					m_currentLevel->m_characters[activeCharacter]->setActive(false);
					activeCharacter = (activeCharacter + 1) % m_currentLevel->m_characters.size();
					m_currentLevel->m_characters[activeCharacter]->setActive(true);
				}
				break;
				/*case sf::Event::Resized:
					m_windowWidth = event.size.width;
					m_windowHeight = event.size.height;

					buildBoard(row, col);
					break;*/
			}
		}
		auto moveDirection = getMovingDirection();
		//auto deltaTime = clock.restart().asSeconds();
		auto deltaTime = m_gameClock.updateTime();

		for (auto& d : dwarfs)
			d->move(d->getDirection(), deltaTime, *this);

		if (moveDirection.x != 0 || moveDirection.y != 0)
			for (auto& c : m_currentLevel->m_characters)
				c->move(moveDirection, deltaTime, *this);

		statusLine.setString(m_gameClock.toString());
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

//todo: change method name
Item* Controller::getItem(const Location l)
{
	for (auto& item : m_currentLevel->m_characters)
		if (item->getLocation() == l)
			return item.get();

	for (auto*& item : dwarfs)
		if (item->getLocation() == l)
			return item;

	for (auto& item : m_currentLevel->m_boardItems)
		if (item->getLocation() == l)
			return item.get();

	return nullptr;
}

sf::Vector2u Controller::getBoardSize()
{
	sf::Vector2u boardSize((m_window.getSize().x) / 100, (m_window.getSize().y) / 100);

	return boardSize;
}

void Controller::buildBoard(int col, int row)
{
	const auto windowSize = m_window.getSize();

	const sf::Vector2f boardSize(static_cast<float>(windowSize.x) * 0.9f, static_cast<float>(windowSize.y) * 0.9f);

	const sf::Vector2f boardOrigin(static_cast<float>(windowSize.x) * 0.05f, static_cast<float>(windowSize.y) * 0.05f);

	/*const auto itemWidth = boardSize.x / col;
	const auto itemHeight = boardSize.y / row;*/

	const sf::Vector2f boardOrigin(static_cast<float>(windowSize.x) * 0.05f, static_cast<float>(windowSize.y) * 0.08f);

	m_boardBorder.setSize(boardSize - sf::Vector2f(3.f, 3.f));
	m_boardBorder.setOutlineThickness(8);
	m_boardBorder.setOutlineColor(sf::Color::Black);
	m_boardBorder.setFillColor(sf::Color::White);
	//m_boardBorder.setOrigin(boardSize / 2.f);
	//m_boardBorder.setPosition(boardOrigin.x + boardSize.x / 2.f, boardOrigin.y + boardSize.y / 2.f);
	m_boardBorder.setPosition(boardOrigin);
}

void Controller::initalizeLevel()
{
	const float item_width = m_boardBorder.getSize().x / static_cast<float>(m_currentLevel->m_cols);
	const float item_height = m_boardBorder.getSize().y / static_cast<float>(m_currentLevel->m_rows);
	const sf::Vector2f itemSize = { item_width, item_height };

	for (auto& item : m_currentLevel->m_boardItems)
	{
		item->setBoardLocation(m_boardBorder.getPosition());
		item->setSize(itemSize);
	}

	for (auto& item : m_currentLevel->m_characters)
	{
		item->setBoardLocation(m_boardBorder.getPosition());
		item->setSize(itemSize);
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