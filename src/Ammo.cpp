#include "Ammo.h"
#include <iostream>

Ammo::Ammo():
	ammoType(AmmoType::AVoidType),
	amountOfAmmo(0),
	maximumAmmo(0),
	damage(0),
	lifeTime(0),
	ammoPulse(0)
{
}

Ammo::Ammo(
	const AmmoType& ammoType,
	const long& amountOfAmmo,
	const long& maximumAmmo,
	const float& damage,
	const float& lifeTime,
	const float& ammoPulse
) :
	ammoType(ammoType),
	amountOfAmmo(amountOfAmmo),
	maximumAmmo(maximumAmmo),
	damage(damage),
	lifeTime(lifeTime),
	ammoPulse(ammoPulse)

{
	//std::cout << ammoTypeToString(ammoType)<< "-----------------" << std::endl;
}

Ammo::Ammo(const AmmoType& ammoType, const bool& isEntyty)
{
	switch (ammoType)
	{
	case AmmoType::AGrenadeLauncherType:
		
		*this = Ammo(ammoType,0,isEntyty?30:4, 65.f, 2.5f, 20);
		break;
	case AmmoType::AVoidType:
		*this = Ammo(ammoType, 0, 0, 0, 0, 0);
		break;
	case AmmoType::AUndefinedType:
		*this = Ammo(ammoType, 0, 0, 0, 0, 0);
		break;
	default:
		*this = Ammo(ammoType, 0, 0, 0, 0, 0);
		break;
	}
}

Ammo::Ammo(const Ammo& ammo):
	ammoType(ammo.ammoType),
	amountOfAmmo(ammo.amountOfAmmo),
	maximumAmmo(ammo.maximumAmmo),
	damage(ammo.damage),
	lifeTime(ammo.lifeTime),
	ammoPulse(ammo.ammoPulse)
{
}

void Ammo::setAmmoType(const AmmoType& ammoType)
{
	this->ammoType = ammoType;
}

const long& Ammo::getAmountOfAmmo()
{
	return amountOfAmmo;
}

void Ammo::setAmountOfAmmo(const long& amountOfAmmo)
{
	this->amountOfAmmo = amountOfAmmo;
}

const long& Ammo::getMaximumAmmo()
{
	return maximumAmmo;
}

void Ammo::setMaximumAmmo(const long& maximumAmmo)
{
	this->maximumAmmo = maximumAmmo;
}

const float& Ammo::getDamge()
{
	return damage;
}

void Ammo::setDamge(const float& damage)
{
	this->damage = damage;
}

const float& Ammo::getLifeTime()
{
	return lifeTime;
}

void Ammo::setLifeTime(const float& lifeTime)
{
	this->lifeTime = lifeTime;
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
	if (other.amountOfAmmo == 0)
	{
		return *this;
	}
	long result = amountOfAmmo + other.amountOfAmmo;
	other.amountOfAmmo = 0;
	if (result > maximumAmmo)
	{
		other.amountOfAmmo = result - maximumAmmo;
		result -= other.amountOfAmmo;
	}
	return Ammo(ammoType, result,maximumAmmo , this->damage, this->lifeTime, this->ammoPulse);
}

const Ammo& Ammo::operator-(Ammo& other)
{
	
	return other + *this;
}

const Ammo& Ammo::operator+(const long& other)
{
	if (other < 0)
	{
		return (*this-(other*-1));
	}
	if (amountOfAmmo == maximumAmmo)
	{
		return *this;
	}
	long result = amountOfAmmo + other;
	long newOther = 0;
	if (result > maximumAmmo)
	{
		newOther = result - maximumAmmo;
		result -= newOther;
	}
	return Ammo(this->ammoType, result, maximumAmmo, this->damage, this->lifeTime, this->ammoPulse);
}

const Ammo& Ammo::operator-(const long& other)
{
	if (other < 0)
	{
		return (*this + (other * -1));
	}
	if (amountOfAmmo <= 0)
	{
		return *this;
	}
	long result = amountOfAmmo - other;
	long newOther = 0;
	if (result < 0)
	{
		newOther = 0 - result;
		result += newOther;
	}
	this->amountOfAmmo = result;
	return Ammo(this->ammoType, result, maximumAmmo, this->damage, this->lifeTime, this->ammoPulse);
}

void Ammo::operator+=(Ammo& other)
{
	*this = *this + other;
}
