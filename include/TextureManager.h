#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <memory>

class TextureManager
{

public:
	void loadTextures(const std::pair<std::string, std::string>* textureList, const int& size);
	std::unordered_map<std::string, sf::Texture> hashMapTextures;

};
