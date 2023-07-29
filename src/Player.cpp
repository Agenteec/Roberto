#include "Player.h"

Player::Player() :
	healthPoints(100.f),
	maxHealthPoints(100.f),
	speed(950.f),
	hitted(false)
{}

void Player::update(const sf::Time& deltaTime)
{
	float dts = deltaTime.asSeconds();
	if (controlFlags.upPressed)
		body->ApplyForceToCenter(b2Vec2(0, -1.f * dts * speed), true);
	if (controlFlags.downPressed)
		body->ApplyForceToCenter(b2Vec2(0, 1.f * dts * speed), true);
	if (controlFlags.leftPressed)
		body->ApplyForceToCenter(b2Vec2 ( - 1.f * dts * speed, 0), true);
	if (controlFlags.rightPressed)
		body->ApplyForceToCenter(b2Vec2(1.f * dts * speed, 0), true);
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

bool Player::isHitted()
{
	return hitted;
}
