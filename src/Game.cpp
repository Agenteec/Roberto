#include "Game.h"



Game::Game():
	gameStatus(1),
	world(b2Vec2(0.f,0.f))
{

}

void Game::init(const std::string& mapPath)
{
	const int texturesCount = 6;
	//   Path \ Name
	std::pair<std::string, std::string> textures[texturesCount] =
	{
	std::pair < std::string, std::string>("Resources/png/entitys/dog.png", "player1"),
	std::pair < std::string, std::string>("Resources/png/entitys/box/box0.png","box0"),
	std::pair < std::string, std::string>("Resources/png/walls/wall1.png","wall1"),
	std::pair < std::string, std::string>("Resources/png/entitys/pepsi.png","pepsi"),
	std::pair < std::string, std::string>("Resources/png/weapons/grenade_launcher.png","grenade_launcher"),
	std::pair < std::string, std::string>("Resources/png/weapons/ammunition/grenade_launcher_ammo.png","grenade_launcher_ammo"),
	};
	textureManager.loadTextures(textures, texturesCount);
	//Temp
	level.load(mapPath);
	level.parse(gameObjects, &textureManager, world);
	
	player.setTexture(*textureManager.textures["player1"]);
	player.setScale(0.3f, 0.3f);
	player.setOrigin(sf::Vector2f(player.getLocalBounds().width / 2.f, player.getLocalBounds().height / 2.f));
	sf::Vector2f playerSpawnPoint;
	for (auto point:  level.playerSpawn)
	{
		playerSpawnPoint = point;
	}
	player.initBody(&world, playerSpawnPoint);
	player.setBodyOvalShape(player.getLocalBounds().width / 2.f, player.getLocalBounds().height / 2.f,8, 0.05f);
	camera.setTracking(&player);
	

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
	CollisionHandler сollisionHandler;
	world.Step(1.f/60.f, 8, 3);
	player.update(deltaTime);
	level.update(deltaTime);
	camera.update(deltaTime, window);
	//Объекты которые уже прошли провекру на контакт с другими объектами
	std::set<b2Body*> contactedBodies;
	for (auto& gameObject : gameObjects)
	{
		collisionHandler.handleCollision(gameObject, contactedBodies);
		gameObject->update(deltaTime);
		
	}
	std::cout << "dts = " << deltaTime.asSeconds()<<std::endl;
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

void CollisionHandler::handleCollision(GameObject* gameObject, std::set<b2Body*> &contactedBodies)
{
	if (!gameObject->getPhysicalObjectFlag())
	{
		return;
	}
	b2Body* body = static_cast<Entity*>(gameObject)->body;
	contactedBodies.insert(body);

	b2ContactEdge* contactEdge = body->GetContactList();
	while (contactEdge) {
		if (contactEdge->contact->IsTouching()) {
			//Выявлено столкновение с объектом
			//Проверяем, был ли объект уже обработан
			if (contactedBodies.contains(contactEdge->other))
			{
				contactEdge = contactEdge->next;
				continue;
			}
			//Достаём указательна базовый класс Entity
			Entity* userDataA = reinterpret_cast<Entity*>(body->GetUserData().pointer);
			Entity* userDataB = reinterpret_cast<Entity*>(contactEdge->other->GetUserData().pointer);



			if (userDataA != nullptr && userDataB != nullptr) {
				const ObjectType& objA = userDataA->gameObjectData.getGameObjectType();
				const ObjectType& objB = userDataB->gameObjectData.getGameObjectType();
				if (objA == ObjectType::PaperBoxType && objB == ObjectType::PaperBoxType)
				{
					std::cout << ANSI_COLOR_RED;
					std::cout << objectTypeToString(objA) << " collided with " << objectTypeToString(objB) << std::endl;
					std::cout << ANSI_COLOR_RESET;
				}
				else
				{
					std::cout << ANSI_COLOR_BLUE;
					std::cout << objectTypeToString(objA) << " collided with " << objectTypeToString(objB) << std::endl;
					std::cout << ANSI_COLOR_RESET;
				}

			}
		}
		contactEdge = contactEdge->next;
	}
}

