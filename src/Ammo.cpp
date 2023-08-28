#include "Ammo.h"

Ammo::Ammo():
	ammoType(AmmoType::AVoidType),
	amountOfAmmo(0),
	maximumAmmo(0),
	damage(0),
	lifeTime(0)
{
}

Ammo::Ammo(
	const AmmoType& ammoType,
	const size_t& amountOfAmmo,
	const size_t& maximumAmmo,
	const float& damage,
	const float& lifeTime
) :
	ammoType(ammoType),
	amountOfAmmo(amountOfAmmo),
	maximumAmmo(maximumAmmo),
	damage(damage),
	lifeTime(lifeTime)
{
}

void Ammo::setAmmoType(const AmmoType& ammoType)
{
	this->ammoType = ammoType;
}

const size_t& Ammo::getAmountOfAmmo()
{
	return amountOfAmmo;
}

void Ammo::setAmountOfAmmo(const size_t& amountOfAmmo)
{
	this->amountOfAmmo = amountOfAmmo;
}

const size_t& Ammo::getMaximumAmmo()
{
	return maximumAmmo;
}

void Ammo::setMaximumAmmo(const size_t& maximumAmmo)
{
	this->maximumAmmo = maximumAmmo;
}

void Ammo::setDamge(const float& damage)
{
}

const AmmoType& Ammo::getAmmoType()
{
	return this->ammoType;
}

const Ammo& Ammo::operator+(Ammo& other)
{
	//Обработка исключений
	if (ammoType != other.ammoType || amountOfAmmo == maximumAmmo)
	{
		return *this;
	}
	size_t result = amountOfAmmo + other.amountOfAmmo;
	other.amountOfAmmo = 0;
	if (result > maximumAmmo)
	{
		other.amountOfAmmo = result - maximumAmmo;
	}
	return Ammo(ammoType,maximumAmmo, result, this->damage, this->lifeTime);
}

void Ammo::operator+=(Ammo& other)
{
	*this = *this + other;
}
