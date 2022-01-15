#include <iostream>

#include "ResourcesService.h"

ResourcesService* ResourcesService::m_instance = nullptr;

ResourcesService* ResourcesService::instance()
{
	if (m_instance == nullptr)
		m_instance = new ResourcesService();

	return m_instance;
}

ResourcesService::~ResourcesService()
{
	for (auto& i : m_textures)
		delete i;
	
	delete m_instance;
}

//todo: merge to a single method
sf::Texture* ResourcesService::getTexture(std::string textureName)
{
	for (int i = 0; i < m_textureNames.size(); ++i)
		if (m_textureNames[i] == textureName)
			return m_textures[i];

	std::cerr << "Texture " << textureName << " not found" << std::endl;
	
	return nullptr;
}

sf::Font* ResourcesService::getFont(std::string fontName)
{
	for (int i = 0; i < m_fontNames.size(); ++i)
		if (m_fontNames[i] == fontName)
			return m_fonts[i];

	std::cerr << "Font " << fontName << " not found" << std::endl;

	return nullptr;
}

ResourcesService::ResourcesService()
{
	m_textureNames = { "crown.png",
						"fire.png",
						"gate.png",
						"ork.png",
						"thief.png",
						"warrior.png",
						"teleport.png",
						"throne.png",
						"delete.png",
						"open.png",
						"save.png",
						"wall.png",
						"mage.png",
						"dwarf.png",
						"gift.png",
						"background.jpg"};

	m_fontNames = { "Hypeblox.ttf" };

	loadTexture();
	loadFonts();
}

void ResourcesService::loadTexture()
{
	int counter = 0;
	for (const auto& textureName : m_textureNames)
	{
		m_textures.push_back(new sf::Texture());
		m_textures[counter++]->loadFromFile(textureName);
	}
}

void ResourcesService::loadFonts()
{
	int counter = 0;
	for (const auto& fontName : m_fontNames)
	{
		m_fonts.push_back(new sf::Font());
		m_fonts[counter++]->loadFromFile(fontName);
	}
}
