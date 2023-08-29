#include "Weapons/GrenadeLauncher.h"

GrenadeLauncher::GrenadeLauncher():Weapon(
	WeaponType::WGrenadeLauncherType,
	Ammo(AmmoType::AGrenadeLauncherType),
	20.f,
	1.f,
	1.f,
	0.5f,
	false
)
{

}

void GrenadeLauncher::shot(std::vector<GameObject*>& gameObjects, TextureManager& textureManager)
{

}
