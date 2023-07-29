#pragma once
#include <Entity.h>

struct ControlFlags
{
	ControlFlags() :
		upPressed(false),
		leftPressed(false),
		downPressed(false),
		rightPressed(false),
		attackPressed(false)

	{

	}

	bool upPressed;
	bool leftPressed;
	bool downPressed;
	bool rightPressed;
	bool attackPressed;
};


class Player : public Entity
{
public:

	Player();
	ControlFlags controlFlags;

	void update(const sf::Time& deltaTime) override;

	void setHealthPoints(const float& healthPoints);
	void setMaxHealthPoints(const float& maxHealthPoints);
	void setSpeed(const float& speed);
	void setHittedFlag(const bool& hitted);

	const float& getHealthPoints();
	const float& getMaxHealthPoints();
	const float& getSpeed();
	bool isHitted();

private:
	float healthPoints, maxHealthPoints, speed;
	bool hitted;
	bool live;
};

