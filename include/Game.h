#pragma once
#include <vector>
#include "Player.h"
#include "Camera.h"

class Game 
{
	Camera camera;
	Player player;

	int gameStatus;
public:
	Game();

	std::vector<GameObject> gameObjects;
	void handleEvent(sf::Event& event);
	void update(const float &deltaTime, sf::RenderWindow& window);
	void draw(sf::RenderWindow &window);
};
