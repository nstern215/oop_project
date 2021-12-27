#pragma once
#include <SFML/Graphics.hpp>

class ResourcesService
{
public:
	~ResourcesService();
	static ResourcesService* instance();

	sf::Texture* getTexture(std::string textureName);
	
private:
	ResourcesService(const ResourcesService&) = default;
	ResourcesService();
	

	ResourcesService& operator=(const ResourcesService&) = default;
	
	static ResourcesService* m_instance;
	
	std::vector<sf::Texture*> m_textures;
	std::vector<std::string> m_textureNames;

	void loadTexture();
};
