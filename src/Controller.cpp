#include <SFML/Graphics.hpp>
#include <memory>

#include "Controller.h"
#include "BoardItem.h"
#include "Characters.h"

Controller::Controller() :
	m_window(sf::VideoMode(800, 800), "Save the King", sf::Style::Default),
	m_bgColor(39, 72, 245, 0.8)
{}

void Controller::run()
{
	const int row = 10;
	const int col = 10;
	
	std::vector<BoardItem*> boardItems;
	std::vector<Characters*> characters;


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

	m_window.setFramerateLimit(120);

	auto shape = sf::RectangleShape({ 50, 50 });
	shape.setPosition(0, 0);
	shape.setFillColor(sf::Color(100, 100, 200));

	sf::Clock clock;
	float speedPerSecond = 200.f;
	
	while(m_window.isOpen())
	{
		m_window.clear(m_bgColor);
		m_window.draw(boardBorder);
		m_window.draw(shape);
		m_window.display();

		for (auto event = sf::Event{}; m_window.pollEvent(event); )
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;
			}
		}

		sf::Vector2f moveDirectionr(0, 0);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			moveDirectionr.y = -1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			moveDirectionr.y = 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			moveDirectionr.x = 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			moveDirectionr.x = -1;

		auto deltaTime = clock.restart().asSeconds();
		moveDirectionr *= deltaTime * speedPerSecond;

		shape.move(moveDirectionr);
	}
}
