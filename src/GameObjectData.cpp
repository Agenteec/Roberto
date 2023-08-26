#include "GameObjectData.h"

void GameObjectData::setGameObjectType(const ObjectType& objectType)
{
	this->objectType = objectType;
}

const ObjectType& GameObjectData::getGameObjectType()
{
	return this->objectType;
}


std::string objectTypeToString(ObjectType objectType)
{
	switch (objectType)
	{
	case UndefinedType:
		return "UndefinedType";
	case PaperBoxType:
		return "PaperBoxType";
	case PepsiType:
		return "PepsiType";
	case BulletType:
		return "BulletType";
	default:
		return "UndefinedType";
	}
}
