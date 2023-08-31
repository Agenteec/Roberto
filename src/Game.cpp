#include "Game.h"




Game::Game():
	gameStatus(1),
	world(b2Vec2(0.f,0.f))
{

}

void Game::init(const std::string& mapPath)
{
	GlobalConsts::font.loadFromFile("Resources/fonts/impact.ttf");

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
	player.gameObjectData.setGameObjectType(ObjectType::PlayerType);
	player.setPhysicalObjectFlag(true);
	b2BodyUserData& b2UserData = player.body->GetUserData();
	b2UserData.pointer = reinterpret_cast<uintptr_t>(&player);
	camera.setTracking(&player);
	gameObjects.push_back(&player);

	//Temp
}

void Game::handleEvent(sf::Event& event, sf::RenderWindow& window)
{

	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.key.code == sf::Mouse::Left && gameStatus == 1)
		{
			player.controlFlags.attackPressed = true;
		}
	}
	if (event.type == sf::Event::MouseButtonReleased)
	{
		if (event.key.code == sf::Mouse::Left && gameStatus == 1)
		{
			player.controlFlags.attackPressed = false;
		}
	}

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
		if (event.key.code == sf::Keyboard::Num1 && gameStatus == 1)
			player.selectedWeaponIndex = 0;
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
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	// Преобразуем позицию мыши в координаты view
	sf::Vector2f worldPosition = window.mapPixelToCoords(mousePosition);
	player.setTargetCoordinates(sf::Vector2f(worldPosition));

}

void Game::update(const sf::Time& deltaTime, sf::RenderWindow& window)
{
	CollisionHandler сollisionHandler;
	world.Step(60.f*deltaTime.asSeconds(), 8, 3);
	//player.update(deltaTime, gameObjects, textureManager, world);
	level.update(deltaTime);
	camera.update(deltaTime, window);
	//Объекты которые уже прошли провекру на контакт с другими объектами
	std::set<b2Body*> contactedBodies;
	//collisionHandler.handleCollision(&player, contactedBodies, world, gameObjects, textureManager);
	for (auto& gameObject : gameObjects)
	{
		collisionHandler.handleCollision(gameObject, contactedBodies, world, gameObjects, textureManager );
		gameObject->update(deltaTime, gameObjects, textureManager, world);

	}
	for (size_t i = 0; i < player.ammo.size(); i++)
	{

	}

}

void Game::draw(sf::RenderWindow& window)	
{
	level.draw(window);

	for (auto& gameObject : gameObjects)
	{
		window.draw(*gameObject);
		if (gameObject->getPhysicalObjectFlag())
		{
			gameObject->draw(window);
		}
	}

	//window.draw(player);
	//player.draw(window);
	camera.draw(window);
}

void CollisionHandler::handleCollision(GameObject* gameObject, std::set<b2Body*> &contactedBodies, b2World& world, std::vector<GameObject*>& gameObjects, TextureManager& textureManager)
{
	std::set<GameObject*> objectsToRemove;
	if (!gameObject->getPhysicalObjectFlag())
		return;
	//std::cout << objectTypeToString(gameObject->gameObjectData.getGameObjectType()) << std::endl;
	//Достаём указательна базовый класс Entity
	if (gameObject->gameObjectData.getGameObjectType() == ObjectType::DynamicProjectileType)
	{
		DynamicProjectile* dynamicProjectileA = reinterpret_cast<DynamicProjectile*>(gameObject);
		if (dynamicProjectileA->body == nullptr)
			return;

		dynamicProjectileA->body->GetFixtureList();

		contactedBodies.insert(dynamicProjectileA->body);

		b2Fixture* fixture = dynamicProjectileA->body->GetFixtureList();

		b2ContactEdge* contactEdge = dynamicProjectileA->body->GetContactList();
		processContactEdge(dynamicProjectileA, contactEdge, contactedBodies, objectsToRemove, world, textureManager);
	}
	else if(gameObject->gameObjectData.getGameObjectType() != ObjectType::UndefinedType)
	{
		Entity* entityA = reinterpret_cast<Entity*>(gameObject);
		if (entityA->body == nullptr)
			return;

		entityA->body->GetFixtureList();

		contactedBodies.insert(entityA->body);

		b2Fixture* fixture = entityA->body->GetFixtureList();

		b2ContactEdge* contactEdge = entityA->body->GetContactList();
		processContactEdge(entityA, contactEdge, contactedBodies, objectsToRemove, world, textureManager);
	}
	removeObjects(gameObjects, objectsToRemove, world);
}
void CollisionHandler::processContactEdge(GameObject* objectA, b2ContactEdge* contactEdge, std::set<b2Body*>& contactedBodies, std::set<GameObject*>& objectsToRemove, b2World& world, TextureManager& textureManager)
{
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
			//Смотрим, что это за объект
			GameObject* objectB = reinterpret_cast<GameObject*>(contactEdge->other->GetUserData().pointer);



			if (objectB != nullptr) {
				 ObjectType objA = objectA->gameObjectData.getGameObjectType();
				 ObjectType objB = objectB->gameObjectData.getGameObjectType();
				 
				if (objA == ObjectType::ObjectWeaponType || objA == ObjectType::ObjectAmmoType)
				{
					std::swap(objectA, objectB);
					std::swap(objA, objB);

				}
				if (objA == ObjectType::PlayerType )
				{
					Entity* entityA = reinterpret_cast<Entity*>(objectA);
					if (objB == ObjectType::ObjectWeaponType)
					{
						Entity* entityB = reinterpret_cast<Entity*>(objectB);
						bool weapoFlaf = false;
						for (auto weaponB : entityB->weapons)
						{
							for (auto weaponA : entityA->weapons)
							{
								bool ammoFlaf = false;
								if (weaponA->getWeaponType() == weaponB->getWeaponType())
								{
									
									for (auto& ammoA : entityA->ammo)
									{
										if (ammoA.getAmmoType() == weaponB->getAmmoMagazine().getAmmoType())
										{
											ammoA += weaponB->getAmmoMagazine();
											ammoFlaf = true;
											if (weaponB->getAmmoMagazine().getAmountOfAmmo()==0)
											{
												objectsToRemove.insert(entityB);
											}
											break;
										}
									}
									if (!ammoFlaf)
									{
										Ammo ammo(weaponB->getAmmoMagazine().getAmmoType());
										ammo += weaponB->getAmmoMagazine();
										if (weaponB->getAmmoMagazine().getAmountOfAmmo() == 0)
										{
											objectsToRemove.insert(entityB);
										}
										entityA->ammo.push_back(ammo);
									}
									weapoFlaf = true;
									break;
								}
									
									
								
							}
							//Если у игрока ещё нет такого оружия
							if (!weapoFlaf)
							{
								Weapon* weapon = new GrenadeLauncher();
								switch (weaponB->getWeaponType())
								{
								case WeaponType::WGrenadeLauncherType:
									weapon->setTexture(*textureManager.textures["grenade_launcher"]);
									weapon->setTrakingObject(entityA);
									break;
								default:
									break;
								}
								
								entityA->weapons.push_back(weapon);
								
								objectsToRemove.insert(entityB);
								
							}
						}
						
							

					}
					else if(objB == ObjectType::ObjectAmmoType)
					{
						Entity* entityB = reinterpret_cast<Entity*>(objectB);
						bool ammoFlaf = false;
						for (auto& ammoB : entityB->ammo)
						{
							for (auto& ammoA : entityA->ammo)
							{
								if (ammoA.getAmmoType() == ammoB.getAmmoType())
								{
									ammoA += ammoB;
									ammoFlaf = true;
									if (ammoB.getAmountOfAmmo() == 0)
									{
										objectsToRemove.insert(entityB);
									}
									break;
								}
							}
							if (!ammoFlaf)
							{
								Ammo ammo(ammoB.getAmmoType(), true);

								
								ammo += ammoB;
								entityA->ammo.push_back(ammo);

							}
						}
					}

				}
				else if(objA == ObjectType::DynamicProjectileType)
				{
					
				}

			}
		}
		contactEdge = contactEdge->next;
	}

}
void CollisionHandler::removeObjects(std::vector<GameObject*>& gameObjects, std::set<GameObject*>& objectsToRemove, b2World& world)
{
	for (auto object: objectsToRemove)
	{
		world.DestroyBody(reinterpret_cast<Entity*>(object)->body);
		
		gameObjects.erase(std::remove_if(gameObjects.begin(), gameObjects.end(), [&](GameObject* obj) { return obj == object; }), gameObjects.end());
	}
	
}
