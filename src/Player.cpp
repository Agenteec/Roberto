#include "Player.h"

Player::Player() :
	healthPoints(100.f),
	maxHealthPoints(100.f),
	speed(0.8f),
	hitted(false),
	debugMode(false),
	Entity()
{
	setResistanceCoefficient(0.1f);
	bodyDef.fixedRotation = true;



	//Добавляем настройки оружия и боеприпасов
	ammo.push_back(Ammo(AmmoType::AGrenadeLauncherType,0,9,65.f,5.f));
}

void Player::update(const sf::Time& deltaTime)
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
	Entity::update(deltaTime);
}

void Player::setHealthPoints(const float& healthPoints)
{
	this->healthPoints = healthPoints;
}

void Player::setMaxHealthPoints(const float& maxHealthPoints)
{
	this->maxHealthPoints = maxHealthPoints;
}

void Player::setSpeed(const float& speed)
{
	this->speed = speed;
}

void Player::setHittedFlag(const bool& hitted)
{
	this->hitted = hitted;
}

void Player::setDebugMode(const bool& mode)
{
	this->debugMode = mode;
}

const float& Player::getHealthPoints()
{
	return healthPoints;
}

const float& Player::getMaxHealthPoints()
{
	return maxHealthPoints;
}

const float& Player::getSpeed()
{
	return speed;
}

const bool& Player::isHitted()
{
	return hitted;
}

const bool& Player::getDebugMode()
{
	return debugMode;
}
