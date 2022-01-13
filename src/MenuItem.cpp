#include "MenuItem.h"

#include "ResourcesService.h"

MenuItem::MenuItem(sf::Vector2f position, void (Controller::* onClick)(), std::string textureName):
	m_frame({75, 75}),
	m_textureRectangle({80, 80}),
	m_onClick(onClick)
{
	m_frame.setPosition(position);
	m_textureRectangle.setPosition(position);
	
	m_frame.setOutlineColor(sf::Color(77, 69, 69, 80));
	m_frame.setOutlineThickness(5);
	m_frame.setFillColor(sf::Color::Magenta);
	m_textureRectangle.setTexture(ResourcesService::instance()->getTexture(textureName));
}

void MenuItem::draw(sf::RenderWindow& window) const
{
	window.draw(m_frame);
	window.draw(m_textureRectangle);
}


void MenuItem::click(Controller& controller) const
{
	(controller.*m_onClick)();
}

sf::FloatRect MenuItem::getGlobalBound() const
{
	return m_frame.getGlobalBounds();
}

void MenuItem::containsAndClick(sf::Vector2f clickedPoint, Controller& controller) const
{
	if (m_frame.getGlobalBounds().contains(clickedPoint))
		click(controller);
}
