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
	size_t amountOfAmmo;
	/// <summary>
	/// Максимальное колличество боепримасов
	/// </summary>
	size_t maximumAmmo;

	float damage;

	float lifeTime;
public:
	Ammo();
	Ammo(
		const AmmoType& ammoType,
		const size_t& amountOfAmmo,
		const size_t& maximumAmmo,
		const float& damage,
		const float& lifeTime

	);
	
	const AmmoType& getAmmoType();
	void setAmmoType(const AmmoType& ammoType);

	const size_t& getAmountOfAmmo();
	void setAmountOfAmmo(const size_t& amountOfAmmo);

	const size_t& getMaximumAmmo();
	void setMaximumAmmo(const size_t& maximumAmmo);

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
	void operator+=(Ammo& other);



};

