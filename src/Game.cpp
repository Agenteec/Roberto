#include "Game.h"


Game::Game():
	gameStatus(1),
	world(b2Vec2(0.f,0.f))
{

}

void Game::init(const std::string& mapPath)
{
	const int texturesCount = 2;
	std::string textures[texturesCount] =
	{
	"Resources/png/entitys/dog.png",
	"Resources/png/entitys/box/box0.png"
	};
	textureManager.loadTextures(textures, texturesCount);
	//Temp
	level.load(mapPath);
	
	player.setTexture(*textureManager.textures["Resources/png/entitys/dog.png"]);
	//player.setScale(0.3f, 0.3f);
	player.setOrigin(sf::Vector2f(player.getLocalBounds().width * player.getScale().x / 2.f, player.getLocalBounds().height * player.getScale().y / 2.f));
	
	player.initBody(&world, sf::Vector2f(200.f, 200.f));
	//player.setBodyBoxShape(sf::Vector2f(player.getLocalBounds().width, player.getLocalBounds().height),0.1f);
	player.setBodyOvalShape(player.getLocalBounds().width / 2.f, player.getLocalBounds().height / 2.f,8, 0.01f);
	//player.setPhysicalProperties();
	camera.setTracking(&player);
	for (size_t i = 0; i < 50; i++)
	{
		Entity* box = new Entity();
		box->setTexture(*textureManager.textures["Resources/png/entitys/box/box0.png"]);
		//box->setScale(1.f, 1.f);
		box->setOrigin(sf::Vector2f(box->getLocalBounds().width * box->getScale().x / 2.f, box->getLocalBounds().height * box->getScale().y / 2.f));
		box->initBody(&world, sf::Vector2f(400.f, 400.f));
		box->setBodyBoxShape(sf::Vector2f(box->getLocalBounds().width, box->getLocalBounds().height));
		gameObjects.push_back(box);
	}
	

	//Temp
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

void Game::update(const sf::Time& deltaTime, sf::RenderWindow& window)
{
	world.Step(1.f/60.f, 8, 3);
	player.update(deltaTime);
	camera.update(deltaTime, window);
	level.update(deltaTime);
	for (auto& gameObject : gameObjects)
	{
		gameObject->update(deltaTime);
	}
}

void Game::draw(sf::RenderWindow& window)	
{
	level.draw(window);

	for (auto& gameObject : gameObjects)
	{
		window.draw(*gameObject);
	}

	window.draw(player);
}
