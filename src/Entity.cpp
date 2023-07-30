#include "Entity.h"
#include <iostream>
Entity::Entity() :
	body(nullptr),
	fixture(nullptr),
	resistanceCoefficient(0.1f)
{
}

void Entity::initBody(b2World* world, const sf::Vector2f &pos)
{
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(pos.x / GlobalConsts::SCALE, pos.y / GlobalConsts::SCALE);
	body = world->CreateBody(&bodyDef);
}

void Entity::setBodyOvalShape(const float &radius_x, const float &radius_y, const int num_segments, const float& density)
{
	float fnum_segments = static_cast<float>(num_segments);
	b2Vec2 *vertices = new b2Vec2[num_segments];

	for (int i = 0; i < num_segments; ++i) {
		float angle = 2.0f * b2_pi * static_cast<float>(i) / fnum_segments;
		vertices[i].Set(radius_x * getScale().x / GlobalConsts::SCALE * cos(angle), radius_y * getScale().y / GlobalConsts::SCALE * sin(angle));
	}

	bodyShape.Set(vertices, num_segments);
	fixture = body->CreateFixture(&bodyShape, density);
	//delete[] vertices;
}

void Entity::setBodyBoxShape(const sf::Vector2f& size, const float& density)
{
	
	b2Vec2 boxSize(size.x  / 2.f / GlobalConsts::SCALE, size.y  / 2.f / GlobalConsts::SCALE);
	bodyShape.SetAsBox(boxSize.x* getScale().x, boxSize.y* getScale().x);
	fixture = body->CreateFixture(&bodyShape, density);
}

void Entity::setBodyPolygonShape(const b2Vec2* vertices, const int num_segments)
{
	bodyShape.Set(vertices, num_segments);
}

void Entity::setBodyPosition(const sf::Vector2f& vec)
{
	setPosition(vec);
	body->SetTransform(b2Vec2(vec.x / GlobalConsts::SCALE, vec.y / GlobalConsts::SCALE), body->GetAngle());
}

void Entity::setBodyPosition(const b2Vec2& vec)
{
	body->SetTransform(vec, body->GetAngle());
}

void Entity::update(const sf::Time& deltaTime)
{
	if (body == nullptr)
	{
		return;
	}
	applyResistance();
	b2Vec2 pos = body->GetPosition();
	setPosition(pos.x * GlobalConsts::SCALE, pos.y * GlobalConsts::SCALE);
	setRotation(body->GetAngle() * 180.f / 3.14);
}

void Entity::setPhysicalProperties(const float& density, const float& friction, const float& restitution)
{
	fixture->SetDensity(density);
	fixture->SetFriction(friction);
	fixture->SetRestitution(restitution);
}
