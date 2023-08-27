#include "GameObject.h"

GameObject::GameObject() :
	hitboxFlag(true)
{
}

void GameObject::setPhysicalObjectFlag(const bool& physicalObjectFlag)
{
	this->physicalObjectFlag = physicalObjectFlag;
}

void GameObject::setHitboxFlag(const bool& hitboxFlag)
{
	this->hitboxFlag = hitboxFlag;
}
const bool& GameObject::getHitboxFlag()
{
	return hitboxFlag;
}

const bool& GameObject::getPhysicalObjectFlag()
{
	return physicalObjectFlag;
}
