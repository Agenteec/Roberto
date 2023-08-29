#include "DynamicProjectile.h"

DynamicProjectile::DynamicProjectile():
	Ammo(AmmoType::AVoidType),
	body(nullptr),
	fixture(nullptr),
	hitBox(nullptr),
	gameObjectData(ObjectType::DynamicProjectileType)
{

}
void DynamicProjectile::initBody(b2World* world, const sf::Vector2f& pos, const float& angle, const b2BodyType& bodyType)
{
	bodyDef.type = bodyType;
	bodyDef.position.Set(pos.x / GlobalConsts::SCALE, pos.y / GlobalConsts::SCALE);
	bodyDef.angle = angle / 180.f * b2_pi;
	body = world->CreateBody(&bodyDef);
}

void DynamicProjectile::setBodyOvalShape(const float& radius_x, const float& radius_y, const int num_segments, const float& density)
{
	float fnum_segments = static_cast<float>(num_segments);
	b2Vec2* vertices = new b2Vec2[num_segments];
	sf::ConvexShape* hitbox;
	hitbox = new sf::ConvexShape;
	hitbox->setPointCount(num_segments);

	for (int i = 0; i < num_segments; ++i) {
		float angle = 2.0f * b2_pi * static_cast<float>(i) / fnum_segments;
		vertices[i].Set(radius_x * getScale().x / GlobalConsts::SCALE * cos(angle), radius_y * getScale().y / GlobalConsts::SCALE * sin(angle));
		hitbox->setPoint(i, sf::Vector2f(vertices[i].x * GlobalConsts::SCALE, vertices[i].y * GlobalConsts::SCALE));
	}

	bodyShape.Set(vertices, num_segments);
	fixture = body->CreateFixture(&bodyShape, density);

	b2Vec2 entityPosition = body->GetPosition();
	hitbox->setPosition(entityPosition.x, entityPosition.y);
	hitbox->setFillColor(sf::Color(0, 255, 0, 50));
	hitbox->setOutlineColor(sf::Color::Green);
	hitbox->setOutlineThickness(2.0f);
	hitBox = hitbox;
}

void DynamicProjectile::setBodyBoxShape(const sf::Vector2f& size, const float& density)
{

	b2Vec2 boxSize(size.x * getScale().x / 2.f / GlobalConsts::SCALE, size.y * getScale().y / 2.f / GlobalConsts::SCALE);
	bodyShape.SetAsBox(boxSize.x, boxSize.y);
	fixture = body->CreateFixture(&bodyShape, density);

	b2Vec2 entityPosition = body->GetPosition();
	sf::RectangleShape* hitbox;
	hitbox = new sf::RectangleShape(sf::Vector2f(boxSize.x * GlobalConsts::SCALE * 2, boxSize.y * GlobalConsts::SCALE * 2));
	hitbox->setPosition(entityPosition.x, entityPosition.y);
	hitbox->setOrigin(hitbox->getSize() / 2.f);
	hitbox->setFillColor(sf::Color(0, 255, 0, 50));
	hitbox->setOutlineColor(sf::Color::Green);
	hitbox->setOutlineThickness(2.0f);
	hitBox = hitbox;
}


void DynamicProjectile::setBodyPolygonShape(const b2Vec2* vertices, const int num_segments)
{
	bodyShape.Set(vertices, num_segments);

	sf::ConvexShape* hitbox;
	hitbox = new sf::ConvexShape;
	hitbox->setPointCount(num_segments);

	for (int i = 0; i < num_segments; ++i)
	{
		hitbox->setPoint(i, sf::Vector2f(vertices[i].x * GlobalConsts::SCALE, vertices[i].y * GlobalConsts::SCALE));
	}

	b2Vec2 entityPosition = body->GetPosition();
	hitbox->setPosition(entityPosition.x, entityPosition.y);
	hitbox->setFillColor(sf::Color(0, 255, 0, 50));
	hitbox->setOutlineColor(sf::Color::Green);
	hitbox->setOutlineThickness(2.0f);
	hitBox = hitbox;
}


void DynamicProjectile::update(const sf::Time& deltaTime, std::vector<GameObject*>& gameObjects, TextureManager& textureManager)
{
	if (body == nullptr)
	{
		return;
	}
	//applyResistance(deltaTime.asSeconds());
	b2Vec2 pos = body->GetPosition();
	setPosition(pos.x * GlobalConsts::SCALE, pos.y * GlobalConsts::SCALE);
	setRotation(body->GetAngle() * 180.f / 3.14);

	if (hitBox != nullptr)
	{
		hitBox->setPosition(pos.x * GlobalConsts::SCALE, pos.y * GlobalConsts::SCALE);
		hitBox->setRotation(body->GetAngle() * 180.f / 3.14);
	}

}

void DynamicProjectile::draw(sf::RenderWindow& window)
{
	if (GlobalConsts::hitBoxOn && hitBox != nullptr)
	{
		window.draw(*hitBox);
	}

}

void DynamicProjectile::setBodyPosition(const sf::Vector2f& vec)
{
	setPosition(vec);
	body->SetTransform(b2Vec2(vec.x / GlobalConsts::SCALE, vec.y / GlobalConsts::SCALE), body->GetAngle());
}

void DynamicProjectile::setBodyPosition(const b2Vec2& vec)
{
	body->SetTransform(vec, body->GetAngle());
}
