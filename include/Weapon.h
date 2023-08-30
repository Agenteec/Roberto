#pragma once
#include "Ammo.h"
#include "GameObject.h"
#include "TextureManager.h"
#include <SFML/Graphics.hpp>
class Weapon : public sf::Sprite
{
	/// <summary>
	/// Привязка к entity
	/// </summary>
	GameObject* trackingObject;
	/// <summary>
	/// Тип оружия
	/// </summary>
	WeaponType weaponType;
	/// <summary>
	/// Объект отвечающий за магазин(В магазите maxAmmo отличается от maxAmmo у Entity)
	/// </summary>
	Ammo ammoMagazine;
	

	/// <summary>
	/// Импульс с которым будет вылетать снаряд(сумируется с ammoPulse)
	/// </summary>
	float weaponPulse;

	/// <summary>
	/// Время перезарядки
	/// </summary>
	float reloadTime;

	/// <summary>
	/// Прогресс перезарядки
	/// </summary>
	float dReloadTime;

	/// <summary>
	/// Время между выстрелами
	/// </summary>
	float cooldown;

	/// <summary>
	/// Прогресс cooldown
	/// </summary>
	float dCooldown;

	/// <summary>
	/// Точность оружия
	/// </summary>
	float accuracy;

	/// <summary>
	/// Выбрано ли оружие в инвентаре entity
	/// </summary>
	bool avable;
	
	/// <summary>
	/// Флаг перезарядки
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

