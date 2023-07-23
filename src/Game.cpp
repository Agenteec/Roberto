#include "Game.h"

Game::Game()
{

}

void Game::update(const float& deltaTime)
{
	for (auto& gameObject : gameObjects)
	{
		gameObject.update(deltaTime);
	}
}

void Game::draw(sf::RenderWindow& window)
{
	for (auto& gameObject : gameObjects)
	{
		window.draw(gameObject);
	}
}
