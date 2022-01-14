#pragma once

#include <SFML/Graphics.hpp>

#include "Characters.h"

enum {
	UP = 0,
	DOWN = 1,
	RIGHT = 2,
	LEFT = 3
};


class Dwarf : public Characters {

public:

	Dwarf(Location location = { 0,0 }, sf::Vector2f boardLocation = { 0,0 });
	
	bool handleCollision(Characters* item) override;

	void setDirection(const int& direction);
	void chengeDirection();
	sf::Vector2f getDirection();

private:

	int m_go;
	//int m_speed;
	//int m_spaces;

	sf::Vector2f m_direction;
};