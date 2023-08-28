#include "Weapon.h"

Weapon::Weapon():
	weaponType(WeaponType::WVoidType),
	ammoMagazine(Ammo(AmmoType::AVoidType,false)),
	weaponPulse(0.f),
	reloadTime(0.f),
	accuracy(0.f),
	cooldown(0.f)
{
}

Weapon::Weapon
(
	const WeaponType& weaponType,
	const Ammo& ammoMagazine,
	const float& weaponPulse,
	const float& reloadTime,
	const float& accuracy,
	const float& cooldown
):
	weaponType(weaponType),
	ammoMagazine(ammoMagazine),
	weaponPulse(weaponPulse),
	reloadTime(reloadTime),
	accuracy(accuracy),
	cooldown(cooldown)

{
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

const float& Weapon::getAccuracy()
{
	return accuracy;
}

void Weapon::setAccuracy(const float& accuracy)
{
	this->accuracy = accuracy;
}
