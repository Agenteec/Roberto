#pragma once
#include <string>
/// <summary>
/// Все типы объектов для box2d userData
/// </summary>
enum ObjectType {
	UndefinedType,
	PaperBoxType,
	PepsiType,
	BulletType
};
std::string objectTypeToString(ObjectType objectType);
class GameObjectData
{
	/// <summary>
	/// Тип объекта
	/// </summary>
	ObjectType objectType;
public:
	void setGameObjectType(const ObjectType& objectType);
	const ObjectType& getGameObjectType();
};