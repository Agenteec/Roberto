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
	void handleCollision(GameObject* gameObject, std::set<b2Body*>& contactedBodies, b2World& world, std::vector<GameObject*>& gameObjects, TextureManager& textureManager);
	void processContactEdge(Entity* entityA, b2ContactEdge* contactEdge, std::set<b2Body*>& contactedBodies, std::set<GameObject*>& objectsToRemove, b2World& world, TextureManager& textureManager);
	void removeObjects(std::vector<GameObject*>& gameObjects, std::set<GameObject*>& objectsToRemove, b2World& world);
	
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
	void handleEvent(sf::Event& event, sf::RenderWindow& window);
	void update(const sf::Time &deltaTime, sf::RenderWindow& window);
	void draw(sf::RenderWindow &window);
};


