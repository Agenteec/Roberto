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

	Player();

	void setHealthPoints(const float& healthPoints);
	void setMaxHealthPoints(const float& maxHealthPoints);
	void setSpeed(const float& speed);
	void setHittedFlag(const bool& hitted);

	float getHealthPoints();
	float getMaxHealthPoints();
	float getSpeed();
	bool isHitted();

private:
	float healthPoints, maxHealthPoints, speed;
	bool hitted;
};

