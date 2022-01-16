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

	void move(sf::Vector2f destination, float deltaTime, Controller& controller) override;
	
	bool handleCollision(Item* item);
	void setActive(bool active) override;

	void draw(sf::RenderWindow& window) override;

	bool handleCollision(King* item)override;
	bool handleCollision(Thief* item)override;
	bool handleCollision(Mage* item)override;
	bool handleCollision(Warrier* item)override;
	bool handleCollision(Dwarf* item)override;
	bool handleCollision(Wall* item)override;
	bool handleCollision(Fire* item)override;
	bool handleCollision(Gate* item)override;
	bool handleCollision(Ork* item)override;
	bool handleCollision(Throne* item)override;

	void setDirection(const int& direction);
	void changeDirection();
	sf::Vector2f getDirection() const;

private:

	int m_go;
	//int m_speed;
	//int m_spaces;

	sf::Vector2f m_direction;
};