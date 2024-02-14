#include "GameObjectData.h"

GameObjectData::GameObjectData():objectType(ObjectType::UndefinedType)
{
}

GameObjectData::GameObjectData(const ObjectType& objectType) :objectType(objectType)
{

}

void GameObjectData::setGameObjectType(const ObjectType& objectType)
{
	this->objectType = objectType;
}

const ObjectType& GameObjectData::getGameObjectType()
{
	return this->objectType;
}

std::string objectTypeToString(const ObjectType& objectType)
{
	switch (objectType)
	{
	case UndefinedType:
		return "UndefinedType";
	case PaperBoxType:
		return "PaperBoxType";
	case PepsiType:
		return "PepsiType";
	case PlayerType:
		return "PlayerType";
	case ObjectWeaponType:
		return "WeaponType";
	case ObjectAmmoType:
		return "AmmoType";
	case DynamicProjectileType:
		return "DynamicProjectileType";
	default:
		return "UndefinedType";
	}
}

std::string ammoTypeToString(const AmmoType& ammoType)
{
	switch (ammoType)
	{
	case AGrenadeLauncherType:
		return "GrenadeLauncherType";
	case AVoidType:
		return "VoidType";
	case AUndefinedType:
		return "UndefinedType";
	default:
		return "DefoultUndefinedType";
	}
}

std::string weaponTypeToString(const WeaponType& weaponType)
{
	switch (weaponType)
	{
	case WGrenadeLauncherType:
		return "GrenadeLauncherType";
	case WVoidType:
		return "VoidType";
	case WUndefinedType:
		return "UndefinedType";
	default:
		return "UndefinedType";
	}
}
