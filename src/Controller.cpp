#include <SFML/Graphics.hpp>
#include <memory>

#include "Controller.h"

#include <iostream>

#include "BoardItem.h"
#include "Characters.h"
#include "King.h"
#include "Mage.h"

Controller::Controller() :
	m_window(sf::VideoMode(800, 800), "Save the King", sf::Style::Default),
	m_bgColor(39, 72, 245, 0.8)
{}



void Controller::run()
{
	int activeCharacter = 0;
	
	const int row = 10;
	const int col = 10;
	
	std::vector<BoardItem*> boardItems;
	std::vector<Characters*> characters;

	characters.push_back(new King({5, 5}));
	characters.push_back(new Mage({ 2, 7 }));

	auto board = buildBoard(col, row);

	m_window.setFramerateLimit(120);

	/*auto shape = sf::RectangleShape({ 50, 50 });
	shape.setPosition(0, 0);
	shape.setFillColor(sf::Color(100, 100, 200));*/

	sf::Clock clock;
	
	
	while(m_window.isOpen())
	{
		m_window.clear(m_bgColor);
		m_window.draw(board);
		//m_window.draw(shape);

		for (auto& item : characters)
			if (!item->isActive())
				item->draw(m_window);

		characters[activeCharacter]->draw(m_window);
		
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
			}
		}

		auto moveDirection = getMovingDirection();
		auto deltaTime = clock.restart().asSeconds();
		
		for (auto& c : characters)
			c->move(moveDirection, deltaTime);		
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

sf::RectangleShape Controller::buildBoard(int col, int row)
{
	const auto windowSize = m_window.getSize();

	sf::Vector2f boardSize(windowSize.x * 0.9f, windowSize.y * 0.9f);

	const auto itemWidth = boardSize.x / col;
	const auto itemHeight = boardSize.y / row;

	sf::Vector2f boardOrigin(windowSize.x * 0.05f, windowSize.y * 0.05f);

	auto boardBorder = sf::RectangleShape(boardSize);
	boardBorder.setSize(boardSize - sf::Vector2f(3.f, 3.f));
	boardBorder.setOutlineThickness(3);
	boardBorder.setOutlineColor(sf::Color::Black);
	boardBorder.setFillColor(sf::Color::White);
	boardBorder.setOrigin(boardSize / 2.f);
	boardBorder.setPosition(boardOrigin.x + boardSize.x / 2.f, boardOrigin.y + boardSize.y / 2.f);

	return boardBorder;
}
