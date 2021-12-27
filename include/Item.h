#pragma once

#include "Location.h"

#include <SFML/Graphics.hpp>
#include <vector>

class Characters;
class Gift;
class Teleport;
class Dwarf;
class Wall;
class Fire;
class Gate;
class Throne;
class Ork;
class Key;

class Item {


public:

    Item(Location location (0,0));
    ~Item();

    bool checkCollision(const GameObject& /*other*/) const

    virtual void handleCollision(Item& item) = 0;
    virtual void handleCollision(Characters& item) = 0;
    virtual void handleCollision(Dwarf& item) = 0;
    virtual void handleCollision(Wall& item) = 0;
    virtual void handleCollision(Gift& item) = 0;
    virtual void handleCollision(Key& item) = 0;
    virtual void handleCollision(Ork& item) = 0;
    virtual void handleCollision(Throne& item) = 0;
    virtual void handleCollision(Gate& item) = 0;
    virtual void handleCollision(Fire& item) = 0;
    virtual void handleCollision(Teleport& item) = 0;

    /*virtual void draw(sf::RenderWindow& window);

    void setPosition(const sf::Vector2f& position);
    
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

    sf::RectangleShape m_rectangle;

    Location m_location;

	bool m_active;

private:
};