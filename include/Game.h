#pragma once
//Game.h
#include <vector>
#include <set>
#include <box2d/box2d.h>
#include "Player.h"
#include "Camera.h"
#include "Level.h"
#include "TextureManager.h"
#include "GlobalConsts.h"

/// <summary>
/// Класс для обработки сколкновений
/// </summary>
class CollisionHandler {
public:
	//Обработка столкновений
	void handleCollision(GameObject* gameObject, std::set<b2Body*>& contactedBodies);
};
class Game 
{
	Camera camera;
	Player player;
	Level level;
	TextureManager textureManager;
	b2World world;
	CollisionHandler collisionHandler;
	int gameStatus;
public:
	Game();

	std::vector<GameObject*> gameObjects;
	void init(const std::string& mapPath);
	void handleEvent(sf::Event& event);
	void update(const sf::Time &deltaTime, sf::RenderWindow& window);
	void draw(sf::RenderWindow &window);
};


