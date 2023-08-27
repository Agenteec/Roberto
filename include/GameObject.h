#pragma once
#include <SFML/Graphics.hpp>

/// <summary>
/// ����������� ����� �������� �������
/// </summary>
class GameObject : public sf::Sprite
{
public:

	GameObject();

	virtual void update(const sf::Time& deltaTime) = 0;
	void setPhysicalObjectFlag(const bool& physicalObjectFlag);
	void setHitboxFlag(const bool& hitboxFlag);
	const bool& getHitboxFlag();
	const bool& getPhysicalObjectFlag();


private:
	/// <summary>
	/// ���� �� � ������� ���� box2d
	/// </summary>
	bool physicalObjectFlag, hitboxFlag;

};