#pragma once

#include <SFML/Graphics.hpp>
#include <tmxlite/Map.hpp>
#include "../include/SFMLOrthogonalLayer.hpp"
#include <vector>
#include <iostream>

class Level
{


public:
	tmx::Map map;
	std::vector<MapLayer*> mapLayers;
	bool load(const std::string path);
	void update(const sf::Time& time);
	void draw(sf::RenderWindow& window);

};