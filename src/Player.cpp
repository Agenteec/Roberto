#include "Player.h"

void move(const FlagsWASD& wasd, sf::Sprite& sprite, const float& deltaTime, const float& speed)
{
	if (wasd.wPressed)
		sprite.move(0, -1.f * deltaTime * speed);
	if (wasd.sPressed)
		sprite.move(0, 1.f * deltaTime * speed);
	if (wasd.aPressed)
		sprite.move(-1.f * deltaTime * speed, 0);
	if (wasd.dPressed)
		sprite.move(1.f * deltaTime * speed, 0);
}

Player::Player() :
	healthPoints(100.f),
	maxHealthPoints(100.f),
	speed(950.f),
	hitted(false)
{}

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

float Player::getHealthPoints()
{
	return healthPoints;
}

float Player::getMaxHealthPoints()
{
	return maxHealthPoints;
}

float Player::getSpeed()
{
	return speed;
}

bool Player::isHitted()
{
	return hitted;
}
