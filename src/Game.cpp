#include "Game.h"


Game::Game():
	gameStatus(1)
{

}

void Game::handleEvent(sf::Event& event)
{
	
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::W && gameStatus == 1)
			player.controlFlags.upPressed = true;
		if (event.key.code == sf::Keyboard::S && gameStatus == 1)
			player.controlFlags.downPressed = true;
		if (event.key.code == sf::Keyboard::A && gameStatus == 1)
			player.controlFlags.leftPressed = true;
		if (event.key.code == sf::Keyboard::D && gameStatus == 1)
			player.controlFlags.rightPressed = true;
	}
	if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::W)
			player.controlFlags.upPressed = false;
		if (event.key.code == sf::Keyboard::S)
			player.controlFlags.downPressed = false;
		if (event.key.code == sf::Keyboard::A)
			player.controlFlags.leftPressed = false;
		if (event.key.code == sf::Keyboard::D)
			player.controlFlags.rightPressed = false;
	}
}

void Game::update(const float& deltaTime, sf::RenderWindow& window)
{
	player.update(deltaTime);
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
