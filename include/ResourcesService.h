#pragma once
#include <mutex>
#include <SFML/Graphics.hpp>

std::mutex m_mutex;

class ResourcesService
{
public:
	static ResourcesService& instance();

private:
	ResourcesService();
	~ResourcesService();
	
	static ResourcesService* m_instance;

	std::vector<sf::Texture*> m_textures;
	std::vector<std::string> m_textureNames;
};
