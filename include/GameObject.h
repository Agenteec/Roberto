#pragma once
#include <SFML/Graphics.hpp>

class GameObject : public sf::Sprite
{
public:

	virtual void update(const float& deltaTime) = 0;
};