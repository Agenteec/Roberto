#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include "GlobalConsts.h"

class Entity : public sf::Sprite
{
public:
	b2BodyDef bodyDef;
	b2Body* body;
	b2Fixture* fixture;
	b2PolygonShape bodyShape;

	void initBody(b2World* world, sf::Vector2f pos);

	void setBodyOvalShape();

	void setBodyBoxShape();

	void setBodyPolygonShape(const b2Vec2 *vertices);

	void setBodyPosition(const sf::Vector2f &vec);

	void setBodyPosition(const b2Vec2 &vec);
};

