#include "ResourcesService.h"

ResourcesService& ResourcesService::instance()
{
	if (m_instance == nullptr)
	{
		std::lock_guard<std::mutex> lock(m_mutex);

		if (m_instance == nullptr)
			m_instance = new ResourcesService();
	}

	return *m_instance;
}

ResourcesService::~ResourcesService()
{
	delete m_instance;
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
}
