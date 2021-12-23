#include <SFML/Graphics.hpp>

#include "Controller.h"

Controller::Controller() :
	m_window(sf::VideoMode(800, 800), "Save the King", sf::Style::Default),
	m_bgColor(39, 72, 245, 0.8)
{}

void Controller::run()
{
	m_window.setFramerateLimit(60);
	
	while(m_window.isOpen())
	{
		m_window.clear(m_bgColor);
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
	}
}
