#pragma once
#include <SFML/Graphics.hpp>

class GameObject : public sf::Sprite
{
public:

	virtual void update(const sf::Time& deltaTime) = 0;

	void setPhysicalObjectFlag(const bool& physicalObjectFlag);

	const bool& getPhysicalObjectFlag();

private:

	bool physicalObjectFlag;

};