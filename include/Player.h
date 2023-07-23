#pragma once
#include <Entity.h>

struct FlagsWASD
{
	FlagsWASD() :
		wPressed(false),
		aPressed(false),
		sPressed(false),
		dPressed(false)
	{

	}

	bool wPressed;
	bool aPressed;
	bool sPressed;
	bool dPressed;
};

void move(const FlagsWASD& wasd, sf::Sprite& sprite, const float& deltaTime, const float& speed);

class Player : public Entity
{
public:

	Player() :
		hp(100.f),
		maxHp(100.f),
		speed(950.f),
		hitted(false)
	{}

	void setHp(const float& hp);
	void setMaxHp(const float& maxHp);
	void setSpeed(const float& speed);
	void setHittedFlag(const bool& hitted);

	float getHp();
	float getMaxHp();
	float getSpeed();
	bool isHitted();

private:
	float hp, maxHp, speed;
	bool hitted;
};

