#include "Weapon.h"
#include <iostream>
Weapon::Weapon() :
	weaponType(WeaponType::WVoidType),
	ammoMagazine(Ammo(AmmoType::AVoidType, false)),
	weaponPulse(0.f),
	reloadTime(0.f),
	dReloadTime(0.f),
	accuracy(0.f),
	cooldown(0.f),
	dCooldown(0.f),
	avable(false),
	reloading(false),
	cooldowning(false),
	trackingObject(nullptr)
{
}

Weapon::Weapon
(
	const WeaponType& weaponType,
	const Ammo& ammoMagazine,
	const float& weaponPulse,
	const float& reloadTime,
	const float& accuracy,
	const float& cooldown,
	const bool& avable,
	GameObject* trackingObject
):
	weaponType(weaponType),
	ammoMagazine(ammoMagazine),
	weaponPulse(weaponPulse),
	reloadTime(reloadTime),
	dReloadTime(0.f),
	accuracy(accuracy),
	cooldown(cooldown),
	dCooldown(0.f),
	avable(avable),
	reloading(false),
	cooldowning(false),
	trackingObject(trackingObject)

{
}

const bool& Weapon::shot(std::vector<GameObject*>& gameObjects, TextureManager& textureManager, GameObject* whoShot, b2World& world)
{
	
	if (reloading||cooldowning)
	{
		return false;
	}
	
	if (ammoMagazine.getAmountOfAmmo() == 0)
	{
		reloading = true;
		std::cout << "Reload..." << std::endl;
		return false;
	}
	else
	{
		ammoMagazine - 1;
		if (ammoMagazine.getAmountOfAmmo() != 0)
		{
			cooldowning = true;
			std::cout << "Cooldown..." << std::endl;
		}
		return true;
			
	}
	return false;
}

void Weapon::update(const float& dts, const float& angle, Ammo& ammo)
{
	//Поворот оружия
	if (trackingObject != nullptr)
	{
		setPosition(trackingObject->getPosition());
		if (!(angle < 270.f && angle > 90.f))
		{
			setScale(getScale().x, (getScale().y > 0) ? getScale().y : getScale().y * -1.f);
		}
		else
		{
			setScale(getScale().x, (getScale().y < 0) ? getScale().y : getScale().y * -1.f);
		}
		setRotation(angle);
	}
	//перезарядка
	if (reloading)
	{
		if (ammo.getAmountOfAmmo() > 0) {
			dReloadTime += dts;
			if (dReloadTime >= reloadTime)
			{
				dReloadTime = 0.f;
				reloading = false;
				ammoMagazine += ammo;
			}
		}
		else
		{
			dReloadTime = 0;
			reloading = false;
		}
	}

	//Перезарядка внутри ствольной коробки
	if (cooldowning)
	{
		if (ammoMagazine.getAmountOfAmmo() > 0) {
			dCooldown += dts;
			if (dCooldown >= cooldown)
			{
				dCooldown = 0.f;
				cooldowning = false;

			}
		}
		else
		{
			dCooldown = 0;
			cooldowning = false;
		}
	}

}

const WeaponType& Weapon::getWeaponType()
{
	return weaponType;
}

void Weapon::setWeaponType(const WeaponType& weaponType)
{
	this->weaponType = weaponType;
}

Ammo& Weapon::getAmmoMagazine()
{
	return ammoMagazine;
}

void Weapon::setAmmoMagazine(const Ammo& ammoMagazine)
{
	this->ammoMagazine = ammoMagazine;
}

const float& Weapon::getWeaponPulse()
{
	return weaponPulse;
}

void Weapon::setWeaponPulse(const float& weaponPulse)
{
	this->weaponPulse = weaponPulse;
}

const float& Weapon::getReloadTime()
{
	return reloadTime;
}

void Weapon::setReloadTime(const float& reloadTime)
{
	this->reloadTime = reloadTime;
}

const float& Weapon::getDReloadTime()
{
	return dReloadTime;
}

void Weapon::setDReloadTime(const float& dReloadTime)
{
	this->dReloadTime = dReloadTime;
}

const float& Weapon::getCooldown()
{
	return cooldown;
}

void Weapon::setCooldown(const float& cooldown)
{
	this->cooldown = cooldown;
}

const float& Weapon::getAccuracy()
{
	return accuracy;
}

void Weapon::setAccuracy(const float& accuracy)
{
	this->accuracy = accuracy;
}

const bool& Weapon::isAvable()
{
	return avable;
}

void Weapon::setAvable(const bool& avable)
{
	this->avable = avable;
}

const bool& Weapon::isReloading()
{
	return reloading;
}

void Weapon::setReload(const bool& reloading)
{
	this->reloading = reloading;
}

const bool& Weapon::isCooldowning()
{
	return cooldowning;
}

void Weapon::setCooldowning(const bool& cooldowning)
{
	this->cooldowning = cooldowning;
}

GameObject* Weapon::getTrakingObject()
{
	return trackingObject;
}

void Weapon::setTrakingObject(GameObject* trakingObject)
{
	this->trackingObject = trakingObject;
}
