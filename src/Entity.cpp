#include "Entity.h"
#include <iostream>
Entity::Entity() :
	healthPoints(-1.f),
	maxHealthPoints(-1.f),
	body(nullptr),
	fixture(nullptr),
	resistanceCoefficient(0.1f)
{
}

void Entity::initBody(b2World* world, const sf::Vector2f &pos, const float& angle, const b2BodyType& bodyType)
{
	
	bodyDef.type = bodyType;
	bodyDef.position.Set(pos.x / GlobalConsts::SCALE, pos.y / GlobalConsts::SCALE);
	bodyDef.angle =angle/180.f * b2_pi;
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
	
	b2Vec2 boxSize(size.x * getScale().x / 2.f / GlobalConsts::SCALE, size.y * getScale().y / 2.f / GlobalConsts::SCALE);
	bodyShape.SetAsBox(boxSize.x, boxSize.y);
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
	applyResistance(deltaTime.asSeconds());
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

void Entity::applyResistance(const float& deltaTime)
{
	b2Vec2 velocity = body->GetLinearVelocity();

	b2Vec2 resistance_force = -resistanceCoefficient * velocity ;

	body->ApplyForceToCenter(resistance_force, true);


}


void Entity::setResistanceCoefficient(const float& resistanceCoefficient)
{
	this->resistanceCoefficient = resistanceCoefficient;
}

void Entity::setHealthPoints(const float& healthPoints)
{
	this->healthPoints = healthPoints;
}

void Entity::setMaxHealthPoints(const float& maxHealthPoints)
{
	this->maxHealthPoints = maxHealthPoints;
}

void Entity::setHittedFlag(const bool& hitted)
{
	this->hitted = hitted;
}

const float& Entity::getResistanceCoefficient()
{
	return this->resistanceCoefficient;
}

const float& Entity::getHealthPoints()
{
	return healthPoints;
}

const float& Entity::getMaxHealthPoints()
{
	return maxHealthPoints;
}

const bool& Entity::isHitted()
{
	return hitted;
}
