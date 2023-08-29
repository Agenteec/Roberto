#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "TextureManager.h"

/// <summary>
/// Абстрактный класс игрового объекта
/// </summary>
class GameObject : public sf::Sprite
{
public:

	GameObject();

	virtual void update(const sf::Time& deltaTime, std::vector<GameObject*>& gameObjects, TextureManager& textureManager) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	void setPhysicalObjectFlag(const bool& physicalObjectFlag);
	void setHitboxFlag(const bool& hitboxFlag);
	const bool& getHitboxFlag();
	const bool& getPhysicalObjectFlag();


private:
	/// <summary>
	/// Есть ли у объекта тело box2d
	/// </summary>
	bool physicalObjectFlag, hitboxFlag;

};