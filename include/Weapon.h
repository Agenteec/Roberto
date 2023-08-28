#pragma once
#include "Ammo.h"
#include <SFML/Graphics.hpp>
class Weapon : public sf::Sprite
{
	/// <summary>
	/// ��� ������
	/// </summary>
	WeaponType weaponType;
	/// <summary>
	/// ������ ���������� �� �������(� �������� maxAmmo ���������� �� maxAmmo � Entity)
	/// </summary>
	Ammo ammoMagazine;
	

	/// <summary>
	/// ������� � ������� ����� �������� ������(���������� � ammoPulse)
	/// </summary>
	float weaponPulse;

	/// <summary>
	/// ����� �����������
	/// </summary>
	float reloadTime;

	/// <summary>
	/// ����� ����� ����������
	/// </summary>
	float cooldown;

	/// <summary>
	/// �������� ������
	/// </summary>
	float accuracy;
public:
	Weapon();

	Weapon
	(
		const WeaponType& weaponType = WeaponType::WVoidType,
		const Ammo& ammoMagazine = Ammo(AmmoType::AVoidType),
		const float& weaponPulse = 0.f,
		const float& reloadTime = 0.f,
		const float& accuracy = 0.f,
		const float& cooldown = 0.f



	);

	const WeaponType& getWeaponType();
	void setWeaponType(const WeaponType& weaponType);

	Ammo& getAmmoMagazine();
	void setAmmoMagazine(const Ammo& ammoMagazine);

	const float& getWeaponPulse();
	void setWeaponPulse(const float& weaponPulse);

	const float& getReloadTime();
	void setReloadTime(const float& reloadTime);

	const float& getAccuracy();
	void setAccuracy(const float& accuracy);


};

