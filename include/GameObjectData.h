#pragma once
#include <string>
/// <summary>
/// ��� ���� �������� ��� box2d userData
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
	/// ��� �������
	/// </summary>
	ObjectType objectType;
public:
	void setGameObjectType(const ObjectType& objectType);
	const ObjectType& getGameObjectType();
};