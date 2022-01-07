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
	~Dwarf();

	void handleCollision(Item* item) override;
	void handleCollision(Key* item) override;
	void handleCollision(Ork* item) override;
	void handleCollision(Throne* item) override;
	void handleCollision(Gate* item) override;
	void handleCollision(Fire* item) override;
	void handleCollision(Teleport* item) override;
	void handleCollision(Characters* item) override;
	void handleCollision(Dwarf* item) override;
	void handleCollision(Wall* item) override;
	void handleCollision(Gift* item) override;

	void setDirection(const int& direction);
	void chengeDirection();
	sf::Vector2f getDirection();

private:

	int m_go;
	//int m_speed;
	//int m_spaces;

	sf::Vector2f m_direction;
};