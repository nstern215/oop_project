#pragma once

#include "Item.h"

class Characters : public Item {

public:

	virtual void move(sf::Vector2f destination);

	virtual draw(sf::RenderWindow& window);
	
	void setIsActive();

protected:

	bool m_isActive;

private:

};