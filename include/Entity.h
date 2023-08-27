#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include "GlobalConsts.h"
#include "GameObject.h"
#include "GameObjectData.h"

class Entity : public GameObject
{
public:
	b2BodyDef bodyDef;
	b2Body* body;
	b2Fixture* fixture;
	b2PolygonShape bodyShape;
	GameObjectData gameObjectData;
	
	Entity();

	void initBody(b2World* world, const sf::Vector2f &pos, const float& angle = 0.f, const b2BodyType& bodyType = b2_dynamicBody);

	void setBodyOvalShape(const float& radius_x, const float& radius_y, const int num_segments = 8, const float& density = 1.f);

	void setBodyBoxShape(const sf::Vector2f &size, const float& density = 1.f);

	void setBodyPolygonShape(const b2Vec2* vertices, const int num_segments = 4);

	void setBodyPosition(const sf::Vector2f &vec);

	void setBodyPosition(const b2Vec2 &vec);

	void virtual update(const sf::Time& deltaTime);

	void drawHitbox(sf::RenderWindow& window);

	void setPhysicalProperties(const float& density, const float& friction, const float& restitution);

	void applyResistance(const float& deltaTime);

	void setResistanceCoefficient(const float& resistanceCoefficient);
	void setHealthPoints(const float& healthPoints);
	void setMaxHealthPoints(const float& maxHealthPoints);
	void setHittedFlag(const bool& hitted);

	const float& getResistanceCoefficient();
	const float& getHealthPoints();
	const float& getMaxHealthPoints();
	const bool& isHitted();


private: 
	//Коэффициент сопротивления(Для того, чтобы объекты постепенно останавливались) 
	float resistanceCoefficient;
	float healthPoints, maxHealthPoints;
	bool hitted;
	sf::Shape* hitBox;

};

