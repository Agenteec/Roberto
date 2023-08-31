#include "Player.h"

Player::Player() :
	speed(0.4f),
	debugMode(false),
	live(true),
	Entity()
{
	setMaxHealthPoints(100.f);
	setHealthPoints(100.f);

	setResistanceCoefficient(1.f);

	bodyDef.fixedRotation = true;
}

void Player::update(const sf::Time& deltaTime, std::vector<GameObject*>& gameObjects, TextureManager& textureManager, b2World& world)
{
	float dts = deltaTime.asSeconds();
	if (controlFlags.upPressed)
		body->ApplyLinearImpulseToCenter(b2Vec2(0, -1.f * dts * speed), true);
	if (controlFlags.downPressed)
		body->ApplyLinearImpulseToCenter(b2Vec2(0, 1.f * dts * speed), true);
	if (controlFlags.leftPressed)
		body->ApplyLinearImpulseToCenter(b2Vec2 ( - 1.f * dts * speed, 0), true);
	if (controlFlags.rightPressed)
		body->ApplyLinearImpulseToCenter(b2Vec2(1.f * dts * speed, 0), true);
	if (controlFlags.attackPressed)
	{
		
		if (!weapons.empty() && selectedWeaponIndex != -1) {
			
			Weapon* w = weapons[selectedWeaponIndex];
			w->shot(gameObjects, textureManager,this, world);
		}
	}
	Entity::update(deltaTime, gameObjects, textureManager, world);
}

void Player::setSpeed(const float& speed)
{
	this->speed = speed;
}


void Player::setDebugMode(const bool& mode)
{
	this->debugMode = mode;
}

const float& Player::getSpeed()
{
	return speed;
}

const bool& Player::getDebugMode()
{
	return debugMode;
}
