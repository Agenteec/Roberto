#pragma once
//GrenadeLauncher.h
#include "Weapon.h"

#include "Ammo/AmmoGrenadeLauncher.h"

class GrenadeLauncher: public Weapon
{
public:
	GrenadeLauncher();
	void shot(std::vector<GameObject*>& gameObjects, TextureManager& textureManager) override;
private:

};