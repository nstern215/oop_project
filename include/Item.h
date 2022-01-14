#pragma once

#include "Location.h"

#include <SFML/Graphics.hpp>
#include <vector>

class Controller;
class Characters;
class BoardItem;

class Item {


public:

    Item(Location location = { 0,0 }, sf::Vector2f boardLocation = { 0, 0 }, float speedPerSecond = 200.f);
    virtual ~Item();

    bool handleCollision(Item* item);
    virtual bool handleCollision(Characters* item) = 0;

    Location getLocation() const;
    void setBoardLocation(sf::Vector2f position);
    sf::Vector2f getPosition() const;

    virtual void setSize(sf::Vector2f size);
	
    virtual void draw(sf::RenderWindow& window);

    /*void setPosition(const sf::Vector2f& position);
    
    void setPosition(float positionOffsetX, float positionOffsetY);
    
    void setInfo(std::string info);
    
    void setTexture(sf::Texture* texture);

    virtual std::string getInfo() const;

    sf::Vector2f getPosition() const;

    sf::FloatRect getGlobalBound();

	sf::Rect getBoundingRectangle();
	
	bool isActive() const;
	
	Location getLocation() const;*/

protected:

    float m_speedPerSecond;

    sf::Vector2f m_boardLocation;
    sf::RectangleShape m_rectangle;
    Location m_location;

	bool m_active;

private:
};