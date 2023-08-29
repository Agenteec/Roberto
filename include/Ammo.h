#pragma once
#include "GameObjectData.h"


class Ammo
{
	/// <summary>
	/// Тип боеприпаса
	/// </summary>
	AmmoType ammoType;
	/// <summary>
	/// Колличество боепримасов
	/// </summary>
	long amountOfAmmo;
	/// <summary>
	/// Максимальное колличество боепримасов
	/// </summary>
	long maximumAmmo;
	/// <summary>
	/// Урон снаряда(суммируется с Weapon::damage)
	/// </summary>
	float damage;
	/// <summary>
	/// Время полёта снаряда
	/// </summary>
	float lifeTime;

	/// <summary>
	/// Импульс с которым будет вылетать снаряд(сумируется с weaponPulse)
	/// </summary>
	float ammoPulse;
public:
	Ammo();
	Ammo(
		const AmmoType& ammoType,
		const long& amountOfAmmo,
		const long& maximumAmmo,
		const float& damage,
		const float& lifeTime,
		const float& ammoPulse

	);
	Ammo(const AmmoType& ammoType = AmmoType::AVoidType, const bool& isEntyty = true);
	Ammo(const Ammo& ammo);
	
	const AmmoType& getAmmoType();
	void setAmmoType(const AmmoType& ammoType);

	const long& getAmountOfAmmo();
	void setAmountOfAmmo(const long& amountOfAmmo);

	const long& getMaximumAmmo();
	void setMaximumAmmo(const long& maximumAmmo);

	const float& getDamge();
	void setDamge(const float& damage);

	const float& getLifeTime();
	void setLifeTime(const float& lifeTime);

	/// <summary>
	/// Данный оператор отнимает боеприпасы у другого объекта и суммирует с боеприпасами данного объектра, создавая новый объект
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	const Ammo& operator+(Ammo& other);
	const Ammo& operator-(Ammo& other);
	const Ammo& operator+(const long& other);
	const Ammo& operator-(const long& other);

	void operator+=(Ammo& other);



};

