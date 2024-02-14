#pragma once
//GrenadeLauncher.h
#include "Weapon.h"

#include "Ammo/AmmoGrenadeLauncher.h"

class GrenadeLauncher: public Weapon
{
public:
	GrenadeLauncher();
	const bool& shot(std::vector<GameObject*>& gameObjects, TextureManager& textureManager, GameObject* whoShot, b2World& world) override;
private:

};