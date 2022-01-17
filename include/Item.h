#pragma once

#include "Location.h"

#include <SFML/Graphics.hpp>
#include <vector>

class King;
class Thief;
class Key;
class Ork;
class Throne;
class Gate;
class Wall;
class Teleport;
class Dwarf;
class Mage;
class Warrier;
class Fire;
class Gift;

class Item {


public:

    Item(Location location = { 0,0 }, sf::Vector2f boardLocation = { 0, 0 }, float speedPerSecond = 200.f);
    virtual ~Item();

    virtual bool handleCollision(Item* item) = 0;
    virtual bool handleCollision(King* item);
    virtual bool handleCollision(Thief* item);
    virtual bool handleCollision(Mage* item);
    virtual bool handleCollision(Warrier* item);
    virtual bool handleCollision(Dwarf* item);
    virtual bool handleCollision(Wall* item);
    virtual bool handleCollision(Key* item);
    virtual bool handleCollision(Teleport* item);
    virtual bool handleCollision(Fire* item);
    virtual bool handleCollision(Gate* item);
    virtual bool handleCollision(Ork* item);
    virtual bool handleCollision(Throne* item);
                                   
    Location getLocation() const;
    void setBoardLocation(sf::Vector2f position);
    sf::Vector2f getPosition() const;

    virtual void setSize(sf::Vector2f size);
	
    virtual void draw(sf::RenderWindow& window);

    void updatePosition();
	
    /*void setPosition(const sf::Vector2f& position);
    
    void setPosition(float positionOffsetX, float positionOffsetY);
    
    void setInfo(std::string info);
    
    void setTexture(sf::Texture* texture);

    virtual std::string getInfo() const;

    sf::Vector2f getPosition() const;

    sf::FloatRect getGlobalBound();

	sf::Rect getBoundingRectangle();
	
	
	
	Location getLocation() const;*/

    bool isActive() const;
    virtual void setActive(bool active);

protected:

    float m_speedPerSecond;

    sf::Vector2f m_boardLocation;
    sf::RectangleShape m_rectangle;
    sf::RectangleShape m_frame;
    Location m_location;

	bool m_isActive;

private:
};