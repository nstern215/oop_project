#include "Item.h"

Item::Item(ItemInfo* itemInfo, int row, int col, float positionOffsetX, float positionOffsetY) :
	m_row(row),
	m_col(col),
	m_itemInfo(itemInfo)
{
	setPosition(positionOffsetX, positionOffsetY);

	if (!m_itemInfo)
	{
		m_itemInfo = new ItemInfo();
		m_itemInfo->m_texture = nullptr;
		m_itemInfo->m_itemData = " ";
	}
}

Item::~Item()
{
	delete m_itemInfo;
};

void Item::draw(sf::RenderWindow& window)
{
	m_square.draw(window);
}

void Item::setPosition(const sf::Vector2f& position)
{
	setPosition(position.x, position.y);
}

void Item::setPosition(float positionOffsetX, float positionOffsetY)
{
	m_square.setPosition({ m_col * m_square.getWidth() + positionOffsetX,
						  m_row * m_square.getHeight() + positionOffsetY });
}


sf::Vector2f Item::getPosition() const
{
	return m_square.getPosition();
}


sf::FloatRect Item::getGlobalBound()
{
	return m_square.getGlobalBound();
}

void Item::onMouseClick(sf::Event& event, sf::Vector2f location, Controller& controller)
{
}

std::string Item::getInfo() const
{
	return m_itemInfo->m_itemData;
}

void Item::setInfo(std::string info)
{
	m_itemInfo->m_itemData = info;
}

void Item::setTexture(sf::Texture* texture)
{
	m_square.setTexture(texture);
}
