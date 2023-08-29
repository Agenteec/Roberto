#pragma once
#include "Ammo.h"
#include "GameObject.h"
#include "GlobalConsts.h"
#include <box2d/box2d.h>
class DynamicProjectile : public Ammo, public GameObject
{
public:
	DynamicProjectile();
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

	void update(const sf::Time& deltaTime, std::vector<GameObject*>& gameObjects, TextureManager& textureManager);

	void draw(sf::RenderWindow& window);

	void setBodyPosition(const sf::Vector2f& vec);

	void setBodyPosition(const b2Vec2& vec);
	#pragma endregion
private:
	/// <summary>
	/// Фигура hitBox
	/// </summary>
	sf::Shape* hitBox;

	/// <summary>
	/// Координаты для цели(для оружия)
	/// </summary>
	sf::Vector2f targetCoordinates;
};