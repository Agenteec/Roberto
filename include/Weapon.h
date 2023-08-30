#pragma once
#include "Ammo.h"
#include "GameObject.h"
#include "TextureManager.h"
#include <SFML/Graphics.hpp>
class Weapon : public sf::Sprite
{
	/// <summary>
	/// �������� � entity
	/// </summary>
	GameObject* trackingObject;
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
	/// �������� �����������
	/// </summary>
	float dReloadTime;

	/// <summary>
	/// ����� ����� ����������
	/// </summary>
	float cooldown;

	/// <summary>
	/// �������� cooldown
	/// </summary>
	float dCooldown;

	/// <summary>
	/// �������� ������
	/// </summary>
	float accuracy;

	/// <summary>
	/// ������� �� ������ � ��������� entity
	/// </summary>
	bool avable;
	
	/// <summary>
	/// ���� �����������
	/// </summary>
	bool reloading;


public:
	Weapon();

	Weapon
	(
		const WeaponType& weaponType = WeaponType::WVoidType,
		const Ammo& ammoMagazine = Ammo(AmmoType::AVoidType),
		const float& weaponPulse = 0.f,
		const float& reloadTime = 0.f,
		const float& accuracy = 0.f,
		const float& cooldown = 0.f,
		const bool& avable = false,
		GameObject* trackingObject = nullptr

	);

	virtual void shot(std::vector<GameObject*>& gameObjects, TextureManager& textureManager);

	void update(const float& dts,const float& angle, Ammo& ammo);

	const WeaponType& getWeaponType();
	void setWeaponType(const WeaponType& weaponType);

	Ammo& getAmmoMagazine();
	void setAmmoMagazine(const Ammo& ammoMagazine);

	const float& getWeaponPulse();
	void setWeaponPulse(const float& weaponPulse);

	const float& getReloadTime();
	void setReloadTime(const float& reloadTime);

	const float& getDReloadTime();
	void setDReloadTime(const float& dReloadTime);

	const float& getCooldown();
	void setCooldown(const float& cooldown);

	const float& getAccuracy();
	void setAccuracy(const float& accuracy);

	const bool& isAvable();
	void setAvable(const bool& avable);

	const bool& isReloading();
	void setReload(const bool& reloading);

	GameObject* getTrakingObject();
	void setTrakingObject(GameObject* trakingObject);


};

