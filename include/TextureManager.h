#pragma once
#include <SFML/Graphics.hpp>
#include <Thor/Resources.hpp>
class TextureManager
{
	thor::ResourceLoader<sf::Texture> textureLoader;
public:
	void loadTextures(const std::pair<std::string, std::string>* textureList, const int& size);
	std::map<std::string, sf::Texture&> textures;


};
