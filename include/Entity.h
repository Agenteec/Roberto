#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include "GlobalConsts.h"
#include "GameObject.h"

class Entity : public GameObject
{
public:
	b2BodyDef bodyDef;
	b2Body* body;
	b2Fixture* fixture;
	b2PolygonShape bodyShape;
	
	void initBody(b2World* world, const sf::Vector2f &pos);

	void setBodyOvalShape(const float& radius_x, const float& radius_y, const int num_segments = 16);

	void setBodyBoxShape(const sf::Vector2f &size);

	void setBodyPolygonShape(const b2Vec2* vertices, const int num_segments = 4);

	void setBodyPosition(const sf::Vector2f &vec);

	void setBodyPosition(const b2Vec2 &vec);

	void virtual update(const float& deltaTime);

private: 

	void setPhysicalProperties(const float &density, const float &friction, const float &restitution);
};

