#pragma once
#include <string>
/// <summary>
/// Все типы объектов для box2d userData
/// </summary>
enum ObjectType {
	UndefinedType,
	PlayerType,
	PaperBoxType,
	PepsiType,
	ObjectWeaponType,
	ObjectAmmoType,
	DynamicProjectileType
};
enum AmmoType
{
	AUndefinedType,
	AGrenadeLauncherType,
	AVoidType,

};
enum WeaponType
{
	WUndefinedType,
	WGrenadeLauncherType,
	WVoidType,

};
std::string objectTypeToString(const ObjectType& objectType);
std::string ammoTypeToString(const AmmoType& ammoType);
std::string weaponTypeToString(const WeaponType& weaponType);

class GameObjectData
{
	/// <summary>
	/// Тип объекта
	/// </summary>
	ObjectType objectType;
public:
	GameObjectData();
	GameObjectData(const ObjectType& objectType);
	void setGameObjectType(const ObjectType& objectType);
	const ObjectType& getGameObjectType();
};