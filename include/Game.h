#pragma once
#include <vector>
#include <box2d/box2d.h>
#include "Player.h"
#include "Camera.h"
#include "Level.h"
#include "TextureManager.h"
class Game 
{
	Camera camera;
	Player player;
	Level level;
	TextureManager textureManager;
	b2World world;
	
	int gameStatus;
public:
	Game();

	std::vector<GameObject*> gameObjects;
	void init(const std::string& mapPath);
	void handleEvent(sf::Event& event);
	void update(const sf::Time &deltaTime, sf::RenderWindow& window);
	void draw(sf::RenderWindow &window);
	void collisionDetector();
};
