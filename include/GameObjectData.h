#pragma once
#include <string>
/// <summary>
/// ��� ���� �������� ��� box2d userData
/// </summary>
enum ObjectType {
	UndefinedType,
	PlayerType,
	PaperBoxType,
	PepsiType,
	ObjectWeaponType,
	ObjectAmmoType,
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
	/// ��� �������
	/// </summary>
	ObjectType objectType;
public:
	void setGameObjectType(const ObjectType& objectType);
	const ObjectType& getGameObjectType();
};