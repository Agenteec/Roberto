#include "Entity.h"

void Entity::initBody(b2World* world, const sf::Vector2f pos)
{
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(pos.x / SCALE, pos.y / SCALE);
	body = world->CreateBody(&bodyDef);
}

void Entity::setBodyPosition(const sf::Vector2f& vec)
{
	setPosition(vec);
	body->SetTransform(b2Vec2(vec.x / SCALE, vec.y / SCALE), body->GetAngle());
}

void Entity::setBodyPosition(const b2Vec2& vec)
{
	body->SetTransform(vec, body->GetAngle());
}
