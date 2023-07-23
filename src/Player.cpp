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

void Player::setHp(const float& hp)
{
	this->hp = hp;
}

void Player::setMaxHp(const float& maxHp)
{
	this->maxHp = maxHp;
}

void Player::setSpeed(const float& speed)
{
	this->speed = speed;
}

void Player::setHittedFlag(const bool& hitted)
{
	this->hitted = hitted;
}

float Player::getHp()
{
	return hp;
}

float Player::getMaxHp()
{
	return maxHp;
}

float Player::getSpeed()
{
	return speed;
}

bool Player::isHitted()
{
	return hitted;
}
