#include "TextureManager.h"

void TextureManager::loadTextures(const std::pair<std::string, std::string>* textureList,  const int& size)
{
	for (size_t i = 0; i < size; i++)
	{
		sf::Texture temp;
		if(temp.loadFromFile(textureList[i].first))
		hashMapTextures[textureList[i].second] = temp;
	}
}
