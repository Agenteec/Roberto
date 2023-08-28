#pragma once
#include "GameObjectData.h"

class Ammo
{
	/// <summary>
	/// ��� ����������
	/// </summary>
	AmmoType ammoType;
	/// <summary>
	/// ����������� �����������
	/// </summary>
	size_t amountOfAmmo;
	/// <summary>
	/// ������������ ����������� �����������
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
	/// ������ �������� �������� ���������� � ������� ������� � ��������� � ������������ ������� ��������, �������� ����� ������
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	const Ammo& operator+(Ammo& other);
	void operator+=(Ammo& other);



};

