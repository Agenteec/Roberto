#include "GameObject.h"

void GameObject::setPhysicalObjectFlag(const bool& physicalObjectFlag)
{
	this->physicalObjectFlag = physicalObjectFlag;
}

const bool& GameObject::getPhysicalObjectFlag()
{
	return physicalObjectFlag;
}
