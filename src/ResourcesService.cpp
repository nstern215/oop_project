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

//todo: is it copy the pointer?
sf::Texture* ResourcesService::getTexture(std::string textureName)
{
	for (int i = 0; i < m_textureNames.size(); ++i)
		if (m_textureNames[i] == textureName)
			return m_textures[i];

	std::cerr << "Texture " << textureName << " not found" << std::endl;
	
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
						"mage.png" };

	loadTexture();
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

