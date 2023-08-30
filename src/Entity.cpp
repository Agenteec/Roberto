#include "Entity.h"
#include <iostream>
Entity::Entity() :
	healthPoints(-1.f),
	maxHealthPoints(-1.f),
	body(nullptr),
	fixture(nullptr),
	hitBox(nullptr),
	hitted(false),
	resistanceCoefficient(0.1f),
	selectedAmmoIndex(-1),
	selectedWeaponIndex(-1)
{
	HUD::Label label;
	label.type = HUD::FpsType;
	label.text.setFont(GlobalConsts::font);
	label.text.setString(L"ABOBA");
	label.text.setCharacterSize(30);
	label.text.setFillColor(sf::Color::Green);
	label.text.setPosition(1000, 1000);
	label.positionCoefficient = sf::Vector2f(1.7f, 1.7f);
	headUpDisplay.labels.push_back(label);
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
	//delete[] vertices;
}

void Entity::setBodyBoxShape(const sf::Vector2f& size, const float& density)
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


void Entity::setBodyPolygonShape(const b2Vec2* vertices, const int num_segments)
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

void Entity::setBodyPosition(const sf::Vector2f& vec)
{
	setPosition(vec);
	body->SetTransform(b2Vec2(vec.x / GlobalConsts::SCALE, vec.y / GlobalConsts::SCALE), body->GetAngle());
}

void Entity::setBodyPosition(const b2Vec2& vec)
{
	body->SetTransform(vec, body->GetAngle());
}

void Entity::setTargetCoordinates(const sf::Vector2f& targetCoordinates)
{
	this->targetCoordinates = targetCoordinates;
}

void Entity::update(const sf::Time& deltaTime, std::vector<GameObject*>& gameObjects, TextureManager& textureManager)
{
	float dts = deltaTime.asSeconds();
	if (body == nullptr)
	{
		return;
	}
	applyResistance(dts);
	b2Vec2 pos = body->GetPosition();
	setPosition(pos.x * GlobalConsts::SCALE, pos.y * GlobalConsts::SCALE);
	setRotation(body->GetAngle() * 180.f / 3.14);

	if (hitBox != nullptr)
	{
		hitBox->setPosition(pos.x * GlobalConsts::SCALE, pos.y * GlobalConsts::SCALE);
		hitBox->setRotation(body->GetAngle() * 180.f / 3.14);
	}
	if (!weapons.empty() && selectedWeaponIndex != -1) {
		Weapon* w = weapons[selectedWeaponIndex];
		if (!ammo.empty())
		{
			if (selectedAmmoIndex != -1)
			{
				if (ammo[selectedAmmoIndex].getAmmoType() != w->getAmmoMagazine().getAmmoType())
				{
					for (size_t i = 0; i < ammo.size(); i++)
					{
						selectedAmmoIndex = i;
						if (ammo[i].getAmmoType() == w->getAmmoMagazine().getAmmoType())
						{
							break;
						}
					}
				}

			}
			else
			{
				for (size_t i = 0; i < ammo.size(); i++)
				{
					selectedAmmoIndex = i;
					if (ammo[i].getAmmoType() == w->getAmmoMagazine().getAmmoType())
					{
						break;
					}
				}
			}
			w->update(dts,angleTwoPoints(getPosition(), targetCoordinates), ammo[selectedAmmoIndex]);
		}
		else
		{
			Ammo voidAmmo(AmmoType::AVoidType);
			w->update(dts,angleTwoPoints(getPosition(), targetCoordinates), voidAmmo);
		}


		
	}
		
}

void Entity::draw(sf::RenderWindow& window)
{
	if (GlobalConsts::hitBoxOn && hitBox != nullptr)
	{
		window.draw(*hitBox);
	}
	if (!weapons.empty() && selectedWeaponIndex != -1 ) {
		Weapon* w = weapons[selectedWeaponIndex];
		window.draw(*w);
	}
	
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

const sf::Vector2f& Entity::getTargetCoordinates()
{
	return targetCoordinates;
}

const bool& Entity::isHitted()
{
	return hitted;
}
