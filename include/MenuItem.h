#pragma once

#include <SFML/Graphics.hpp>

class Controller;

class MenuItem
{
public:
	MenuItem(sf::Vector2f position = { 0,0 }, void(Controller::*onClick)() = nullptr, std::string textureName = "");
	sf::FloatRect getGlobalBound() const;
	void click(Controller& controller) const;
	void containsAndClick(sf::Vector2f clickedPoint, Controller& controller) const;
	void draw(sf::RenderWindow& window) const;

private:
	sf::RectangleShape m_frame;
	sf::RectangleShape m_textureRectangle;

	void(Controller::* m_onClick)();
};
