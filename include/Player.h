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

	void update(const sf::Time& deltaTime, std::vector<GameObject*>& gameObjects, TextureManager& textureManager) override;

	void setHealthPoints(const float& healthPoints);
	void setMaxHealthPoints(const float& maxHealthPoints);
	void setSpeed(const float& speed);
	void setHittedFlag(const bool& hitted);
	void setDebugMode(const bool& mode);


	const float& getHealthPoints();
	const float& getMaxHealthPoints();
	const float& getSpeed();
	const bool& isHitted();
	const bool& getDebugMode();

private:
	float healthPoints, maxHealthPoints, speed;
	bool hitted;
	bool live;
	bool debugMode;
};

