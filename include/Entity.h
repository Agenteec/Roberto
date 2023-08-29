#pragma once
//Entity.h
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include "GlobalConsts.h"
#include "GameObject.h"
#include "GameObjectData.h"
#include "GameMath.h"
#include "Weapons/GrenadeLauncher.h"
class Entity : public GameObject
{
public:
	#pragma region Body
	b2BodyDef bodyDef;
	b2Body* body;
	b2Fixture* fixture;
	b2PolygonShape bodyShape;
	#pragma endregion

	/// <summary>
	/// Боеприпасы содержащиеся в entity
	/// </summary>
	std::vector<Ammo> ammo;

	std::vector<Weapon*> weapons;
	/// <summary>
	/// Иедекс оружия в руках
	/// </summary>
	int selectedWeaponIndex;
	/// <summary>
	/// Иедекс снарядов для оружия в руках
	/// </summary>
	int selectedAmmoIndex;
	
	Entity();

	void initBody(b2World* world, const sf::Vector2f &pos, const float& angle = 0.f, const b2BodyType& bodyType = b2_dynamicBody);

	void setBodyOvalShape(const float& radius_x, const float& radius_y, const int num_segments = 8, const float& density = 1.f);

	void setBodyBoxShape(const sf::Vector2f &size, const float& density = 1.f);

	void setBodyPolygonShape(const b2Vec2* vertices, const int num_segments = 4);

	void setBodyPosition(const sf::Vector2f &vec);

	void setBodyPosition(const b2Vec2 &vec);

	void setTargetCoordinates(const sf::Vector2f& targetCoordinates);

	virtual void update(const sf::Time& deltaTime, std::vector<GameObject*>& gameObjects, TextureManager& textureManager);

	void draw(sf::RenderWindow& window) override;

	void setPhysicalProperties(const float& density, const float& friction, const float& restitution);

	void applyResistance(const float& deltaTime);

	void setResistanceCoefficient(const float& resistanceCoefficient);
	void setHealthPoints(const float& healthPoints);
	void setMaxHealthPoints(const float& maxHealthPoints);
	void setHittedFlag(const bool& hitted);

	const float& getResistanceCoefficient();
	const float& getHealthPoints();
	const float& getMaxHealthPoints();
	const sf::Vector2f& getTargetCoordinates();
	const bool& isHitted();


private: 
	//Коэффициент сопротивления(Для того, чтобы объекты постепенно останавливались) 
	float resistanceCoefficient;
	/// <summary>
	/// Очки здоровья
	/// </summary>
	float healthPoints;
	/// <summary>
	/// Максимальные очки здоровья (-1 сущность неуязвима)
	/// </summary>
	float maxHealthPoints;

	bool hitted;

	/// <summary>
	/// Фигура hitBox
	/// </summary>
	sf::Shape* hitBox;

	/// <summary>
	/// Координаты для цели(для оружия)
	/// </summary>
	sf::Vector2f targetCoordinates;
};

