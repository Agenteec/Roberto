#include "Weapons/GrenadeLauncher.h"

GrenadeLauncher::GrenadeLauncher():Weapon(
	WeaponType::WGrenadeLauncherType,
	Ammo(AmmoType::AGrenadeLauncherType, false),
	20.f,
	1.f,
	1.f,
	0.5f,
	false
)
{

}

bool GrenadeLauncher::shot(std::vector<GameObject*>& gameObjects, TextureManager& textureManager, GameObject* whoShot, b2World& world)
{
	bool Shoting = Weapon::shot(gameObjects, textureManager, whoShot, world);
	if (Shoting)
	{
		GrenadeLauncherProjectaile* projectile = new GrenadeLauncherProjectaile();
		projectile->setTexture(*textureManager.textures["grenade_launcher_ammo"]);
		projectile->setOrigin(projectile->getLocalBounds().width / 2.f, projectile->getLocalBounds().height / 2.f);
		projectile->gameObjectData.setGameObjectType(ObjectType::DynamicProjectileType);
		
		// ¬ычисл€ем смещение до центра правой стороны
		sf::Vector2f offsetToRightCenter(getTextureRect().width, getTextureRect().height / 2.f);

		// ѕримен€ем поворот к смещению
		float radians = getRotation() * (3.14159f / 180.f); // ѕереводим угол в радианы
		float sinRadians = std::sin(radians);
		float cosRadiand = std::cos(radians);
		float rotatedX = offsetToRightCenter.x * cosRadiand - offsetToRightCenter.y * sinRadians;
		float rotatedY = offsetToRightCenter.x * sinRadians + offsetToRightCenter.y * cosRadiand;

		// ƒобавл€ем повернутое смещение к исходным координатам левой верхней вершины
		sf::Vector2f rightCenter(getPosition().x + rotatedX, getPosition().y + rotatedY);
		sf::Vector2f pos = sf::Vector2f(rightCenter.x + projectile->getLocalBounds().width * getScale().x / 2.f, rightCenter.y - projectile->getLocalBounds().height * getScale().y / 2.f);
		projectile->initBody(&world, pos, getRotation(), b2_dynamicBody);
		projectile->setBodyBoxShape(sf::Vector2f(projectile->getLocalBounds().width, projectile->getLocalBounds().height),1.f);
		b2BodyUserData& b2UserData = projectile->body->GetUserData();
		b2UserData.pointer = reinterpret_cast<uintptr_t>(projectile);


		projectile->body->ApplyLinearImpulseToCenter(b2Vec2(0.005f * cosRadiand,0.005f * sinRadians), true);
		gameObjects.push_back(projectile);
	}
	return false;
}
