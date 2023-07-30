#include "TextureManager.h"

void TextureManager::loadTextures(std::string textureList[], const int& size)
{
	for (size_t i = 0; i < size; i++)
	{
		sf::Texture* temp = new sf::Texture();
		if (temp->loadFromFile(textureList[i]))
		{
			textures.emplace(textureList[i], temp);
		}
		//hashMapTextures[textureList[i].second] = temp;
	}
}
