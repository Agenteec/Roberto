#pragma once
#include "Ammo.h"
#include "GameObject.h"
#include "GlobalConsts.h"
#include <box2d/box2d.h>
class MyQueryCallback : public b2QueryCallback {
public:
	bool ReportFixture(b2Fixture* fixture) override {
		// Ваш код обработки объекта, например, добавление его в список
		bodiesInRange.push_back(fixture->GetBody());
		return true; // true, чтобы продолжить обход объектов
	}

	std::vector<b2Body*> bodiesInRange; // Список объектов в зоне взрыва
};
class DynamicProjectile : public Ammo, public GameObject
{
public:
	DynamicProjectile();
	DynamicProjectile(const AmmoType& ammoType);
	GameObjectData gameObjectData;
	#pragma region Body
	b2BodyDef bodyDef;
	b2Body* body;
	b2Fixture* fixture;
	b2PolygonShape bodyShape;

	void initBody(b2World* world, const sf::Vector2f& pos, const float& angle = 0.f, const b2BodyType& bodyType = b2_dynamicBody);

	void setBodyOvalShape(const float& radius_x, const float& radius_y, const int num_segments = 8, const float& density = 1.f);

	void setBodyBoxShape(const sf::Vector2f& size, const float& density = 1.f);

	void setBodyPolygonShape(const b2Vec2* vertices, const int num_segments = 4);

	void update(const sf::Time& deltaTime, std::vector<GameObject*>& gameObjects, TextureManager& textureManager, b2World& world);

	void applyResistance();

	void draw(sf::RenderWindow& window);

	void setBodyPosition(const sf::Vector2f& vec);

	void setBodyPosition(const b2Vec2& vec);
	#pragma endregion

	void setExplodes(const bool& explodes);
	const bool& isExplodes();

	void setExplosionRadius(const float& explosionRadius);
	const float& getExplosionRadius();

	void setExplosionPulse(const float& explosionPulse);
	const float& getExplosionPulse();

	void destroy(b2World& world, std::vector<GameObject*>& gameObjects);
private:
	/// <summary>
	/// Фигура hitBox
	/// </summary>
	sf::Shape* hitBox;

	/// <summary>
	/// Координаты для цели(для снаряда)
	/// </summary>
	sf::Vector2f targetCoordinates;

	/// <summary>
	/// Запоминаем сущность, которая сделала выстрел
	/// </summary>
	GameObject* whoShot;

	/// <summary>
	/// Взрывается ли снаряд?
	/// </summary>
	bool explodes;

	/// <summary>
	/// Радиус взрыва
	/// </summary>
	float explosionRadius;

	/// <summary>
	/// Импульс взрыва
	/// </summary>
	float explosionPulse;

	/// <summary>
	/// Коэффициент сопроте=ивления воздуха
	/// </summary>
	float resistanceCoefficient;
};