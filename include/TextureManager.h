#pragma once
#include <SFML/Graphics.hpp>
class TextureManager
{
public:
	void loadTextures(std::pair<std::string, std::string> textureList[], const int& size);
	std::map<std::string, sf::Texture*> textures;
	void clear();

};
