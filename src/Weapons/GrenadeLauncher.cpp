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
	if (isReloading())
	{
		return;
	}
	Ammo magazine = getAmmoMagazine();
	if (magazine.getAmountOfAmmo() == 0)
	{
		setReload(true);
	}
	else
	{

	}
}
