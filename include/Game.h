#pragma once
#include <vector>
#include "Player.h"

class Game 
{
public:
	Game();

	std::vector<GameObject> gameObjects;

	void update(const float &deltaTime);
	void draw(sf::RenderWindow &window);
};
