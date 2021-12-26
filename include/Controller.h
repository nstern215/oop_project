#pragma once

#include <SFML/Graphics.hpp>

class Controller{

public:
	Controller();
	void run();

private:
	sf::RenderWindow m_window;
	const sf::Color m_bgColor;

	unsigned int m_windowWidth;
	unsigned int m_windowHeight;
};