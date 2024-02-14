#pragma once
#include "Ammo.h"
#include "GameObject.h"
#include "GlobalConsts.h"
#include <box2d/box2d.h>
class MyQueryCallback : public b2QueryCallback {
public:
	bool ReportFixture(b2Fixture* fixture) override {
		// ��� ��� ��������� �������, ��������, ���������� ��� � ������
		bodiesInRange.push_back(fixture->GetBody());
		return true; // true, ����� ���������� ����� ��������
	}

	std::vector<b2Body*> bodiesInRange; // ������ �������� � ���� ������
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
	/// ������ hitBox
	/// </summary>
	sf::Shape* hitBox;

	/// <summary>
	/// ���������� ��� ����(��� �������)
	/// </summary>
	sf::Vector2f targetCoordinates;

	/// <summary>
	/// ���������� ��������, ������� ������� �������
	/// </summary>
	GameObject* whoShot;

	/// <summary>
	/// ���������� �� ������?
	/// </summary>
	bool explodes;

	/// <summary>
	/// ������ ������
	/// </summary>
	float explosionRadius;

	/// <summary>
	/// ������� ������
	/// </summary>
	float explosionPulse;

	/// <summary>
	/// ����������� �������=������� �������
	/// </summary>
	float resistanceCoefficient;
};