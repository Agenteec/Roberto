#pragma once

#include <SFML/Graphics.hpp>
#include <tmxlite/Map.hpp>
#include "../include/SFMLOrthogonalLayer.hpp"
#include <vector>
#include <iostream>
#include <Player.h>
#include <TextureManager.h>
#include <array>
#include <tmxlite/ObjectGroup.hpp>
#include <tmxlite/LayerGroup.hpp>
#include <tmxlite/TileLayer.hpp>
class Level
{


public:
	tmx::Map map;
	std::vector<MapLayer*> mapLayers;
	bool load(const std::string& path);
	void update(const sf::Time& time);
	void draw(sf::RenderWindow& window);
	void parse(std::vector<GameObject*>& gameObjects, TextureManager* textureManager, b2World& world);
	std::vector<sf::Vector2f> playerSpawn;
};