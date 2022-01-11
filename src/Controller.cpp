#include <SFML/Graphics.hpp>
#include <memory>

#include "Controller.h"

#include <iostream>

#include "BoardItem.h"
#include "Characters.h"
#include "King.h"
#include "Mage.h"
#include "Dwarf.h"

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

	sf::Vector2f boardPosition = m_boardBorder.getPosition();
	//sf::Vector2f boardPosition(0,0);
	
	characters.push_back(new King({ 1, 5 }, boardPosition));
	characters.push_back(new Mage({ 3, 1 }, boardPosition));

	dwarfs.push_back(new Dwarf({ 1, 1 }, boardPosition));
	dwarfs.push_back(new Dwarf({ 2, 1 }, boardPosition));

	//boardItems.push_back(new Wall({ 7,7 }, boardPosition));
	//boardItems.push_back(new Wall({ 6,7 }, boardPosition));
	//boardItems.push_back(new Wall({ 5,7 }, boardPosition));
	//boardItems.push_back(new Wall({ 4,7 }, boardPosition));


	m_window.setFramerateLimit(120);

	/*auto shape = sf::RectangleShape({ 50, 50 });
	shape.setPosition(0, 0);
	shape.setFillColor(sf::Color(100, 100, 200));*/

	sf::Clock clock;


	while (m_window.isOpen())
	{
		m_window.clear(m_bgColor);
		m_window.draw(m_boardBorder);
		//m_window.draw(shape);

		for (auto& item : characters)
			if (!item->isActive())
				item->draw(m_window);

		characters[activeCharacter]->draw(m_window);
		
		for (auto& item : dwarfs)
			item->draw(m_window);

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
					characters[activeCharacter]->setActive(false);
					activeCharacter = (activeCharacter + 1) % characters.size();
					characters[activeCharacter]->setActive(true);
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
		auto deltaTime = clock.restart().asSeconds();
		
		for (auto& c : characters)
			c->move(moveDirection, deltaTime, *this);
		
		for (auto& d : dwarfs)
			d->move(d->getDirection(), deltaTime, *this);
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
	for (auto*& item : characters)
		if (item->getLocation() == l)
			return item;

	for (auto*& item : dwarfs)
		if (item->getLocation() == l)
			return item;

	for (auto*& item : boardItems)
		if (item->getLocation() == l)
			return item;

	return nullptr;
}

sf::Vector2u Controller::getBoardSize()
{
	sf::Vector2u boardSize((m_window.getSize().x)/100, (m_window.getSize().y) / 100);

	return boardSize;
}

void Controller::buildBoard(int col, int row)
{
	const auto windowSize = m_window.getSize();

	const sf::Vector2f boardSize(static_cast<float>(windowSize.x) * 0.9f, static_cast<float>(windowSize.y) * 0.9f);

	const sf::Vector2f boardOrigin(static_cast<float>(windowSize.x) * 0.05f, static_cast<float>(windowSize.y) * 0.05f);
	
	/*const auto itemWidth = boardSize.x / col;
	const auto itemHeight = boardSize.y / row;*/


	m_boardBorder.setSize(boardSize - sf::Vector2f(3.f, 3.f));
	m_boardBorder.setOutlineThickness(8);
	m_boardBorder.setOutlineColor(sf::Color::Black);
	m_boardBorder.setFillColor(sf::Color::White);
	//m_boardBorder.setOrigin(boardSize / 2.f);
	//m_boardBorder.setPosition(boardOrigin.x + boardSize.x / 2.f, boardOrigin.y + boardSize.y / 2.f);
	m_boardBorder.setPosition(boardOrigin);
}

//sf::RectangleShape Controller::getBoardBorder()
//{
//	return m_boardBorder;
//}

bool operator==(const Location& a, const Location& b)
{
	return a.m_row == b.m_row && a.m_col == b.m_col;
}

bool operator!=(const Location& a, const Location& b)
{
	return !(a == b);
}