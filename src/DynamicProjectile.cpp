#include "DynamicProjectile.h"
#include "Entity.h"

DynamicProjectile::DynamicProjectile():
	Ammo(AmmoType::AVoidType),
	body(nullptr),
	fixture(nullptr),
	hitBox(nullptr),
	resistanceCoefficient(0.015f),
	explosionRadius(5.f),
	explosionPulse(0.5f),
	gameObjectData(ObjectType::DynamicProjectileType)
{

}
DynamicProjectile::DynamicProjectile(const AmmoType& ammoType):
	Ammo(ammoType, false),
	body(nullptr),
	fixture(nullptr),
	hitBox(nullptr),
	explosionRadius(5.f),
	explosionPulse(0.5f),
	resistanceCoefficient(0.015f),
	gameObjectData(ObjectType::DynamicProjectileType)
{

}
void DynamicProjectile::initBody(b2World* world, const sf::Vector2f& pos, const float& angle, const b2BodyType& bodyType)
{
	bodyDef.type = bodyType;
	bodyDef.position.Set(pos.x / GlobalConsts::SCALE, pos.y / GlobalConsts::SCALE);
	bodyDef.angle = angle / 180.f * b2_pi;
	body = world->CreateBody(&bodyDef);
	body->SetBullet(true);
	body->SetLinearDamping(resistanceCoefficient);
	
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
	body->SetBullet(true);
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
	body->SetBullet(true);
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
	//Не рабочий код
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
	//Не рабочий код
}

void DynamicProjectile::update(const sf::Time& deltaTime, std::vector<GameObject*>& gameObjects, TextureManager& textureManager, b2World& world)
{
	if (body == nullptr)
	{
		return;
	}
	//applyResistance();
	b2Vec2 pos = body->GetPosition();
	setPosition(pos.x * GlobalConsts::SCALE, pos.y * GlobalConsts::SCALE);
	setRotation(body->GetAngle() * 180.f / 3.14);

	if (hitBox != nullptr)
	{
		hitBox->setPosition(pos.x * GlobalConsts::SCALE, pos.y * GlobalConsts::SCALE);
		hitBox->setRotation(body->GetAngle() * 180.f / 3.14);
	}
	if (getLifeTime() > 0)
	{

		setLifeTime(getLifeTime() - deltaTime.asSeconds());
	}
	else
	{
		destroy(world, gameObjects);
		world.DestroyBody(body);
		gameObjects.erase(std::remove_if(gameObjects.begin(), gameObjects.end(),
			[this](GameObject* obj) { return obj == this; }),
			gameObjects.end());
		
	}
	

}

void DynamicProjectile::applyResistance()
{
	const b2Vec2& velocity = body->GetLinearVelocity();

	b2Vec2 resistance_force = resistanceCoefficient * velocity ;

	body->ApplyLinearImpulseToCenter(resistance_force, true);
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

void DynamicProjectile::setExplodes(const bool& explodes)
{
	this->explodes = explodes;
}

const bool& DynamicProjectile::isExplodes()
{
	return explodes;
}

void DynamicProjectile::setExplosionRadius(const float& explosionRadius)
{
	this->explosionRadius;
}

const float& DynamicProjectile::getExplosionRadius()
{
	return explosionRadius;
}

void DynamicProjectile::setExplosionPulse(const float& explosionPulse)
{
	this->explosionPulse = explosionPulse;
}

const float& DynamicProjectile::getExplosionPulse()
{
	return explosionPulse;
}

void DynamicProjectile::destroy(b2World& world, std::vector<GameObject*>& gameObjects)
{
	b2AABB aabb;
	aabb.lowerBound = body->GetPosition() - b2Vec2(explosionRadius, explosionRadius);
	aabb.upperBound = body->GetPosition() + b2Vec2(explosionRadius, explosionRadius);
	std::vector<b2Body*> bodies;
	for (auto gameOgject: gameObjects)
	{
		
		if (gameOgject->getPhysicalObjectFlag())
		{
			if (gameOgject->gameObjectData.getGameObjectType() == ObjectType::DynamicProjectileType)
			{

				if (reinterpret_cast<DynamicProjectile*>(gameOgject)->body != nullptr)
				{
	/*				for (int32 childIndex = 0; childIndex < reinterpret_cast<DynamicProjectile*>(gameOgject)->fixture->GetShape()->GetChildCount(); ++childIndex) {
						b2AABB fixtureAABB;
						reinterpret_cast<DynamicProjectile*>(gameOgject)->fixture->GetShape()->ComputeAABB(&fixtureAABB, b2Transform(), childIndex);
						if (b2TestOverlap(aabb, fixtureAABB))
						{
							
						}
					}*/
					bodies.push_back(reinterpret_cast<DynamicProjectile*>(gameOgject)->body);
				}


				
			}
			else if(gameOgject->gameObjectData.getGameObjectType() != ObjectType::UndefinedType)
			{
				if (reinterpret_cast<Entity*>(gameOgject)->body != nullptr)
				{
	/*				for (int32 childIndex = 0; childIndex < reinterpret_cast<Entity*>(gameOgject)->fixture->GetShape()->GetChildCount(); ++childIndex) {
						b2AABB fixtureAABB;
						reinterpret_cast<Entity*>(gameOgject)->fixture->GetShape()->ComputeAABB(&fixtureAABB, b2Transform(), childIndex);
						if (b2TestOverlap(aabb, fixtureAABB))
						{
							
						}

					}*/
					bodies.push_back(reinterpret_cast<Entity*>(gameOgject)->body);
				}
				
			}
		}
		
	}
	for (b2Body* b : bodies) {
		b2Vec2 bodyPos = b->GetPosition();
		b2Vec2 explosionDir = bodyPos - body->GetPosition();
		float distance = explosionDir.Length();

		if (distance < explosionRadius) {
			float strength = 1.0f - distance / explosionRadius;
			b2Vec2 impulse = explosionDir;
			impulse.Normalize();
			impulse *= strength * (explosionPulse);

			b->ApplyLinearImpulseToCenter(impulse, true);
		}
	}
}
