#include "TextureManager.h"

void TextureManager::loadTextures(std::pair<std::string, std::string> textureList[], const int& size)
{
	for (size_t i = 0; i < size; i++)
	{
		sf::Texture* temp = new sf::Texture();
		if (temp->loadFromFile(textureList[i].first))
		{
			textures.emplace(textureList[i].second, temp);
		}


	}
	sf::Texture* temp = new sf::Texture();
	temp->create(53,53);
	sf::Uint8* pixels = new sf::Uint8[53 * 53 * 4]; // 4 ���������� RGBA �� ������� (Uint8 - ����������� 8-������ ���)
	for (int y = 0; y < 53; y++) {
		for (int x = 0; x < 53; x++) {
			int index = (x + y * 53) * 4;
			pixels[index] = 128;     // �������
			pixels[index + 1] = 200;   // �������
			pixels[index + 2] = 255;   // �����
			pixels[index + 3] = 100; // ����� 
		}
	}
	temp->update(pixels);

	// ������������ ������, ���������� ��� �������
	delete[] pixels;
	textures.emplace("wall0", temp);
}

void TextureManager::clear()
{
	for (auto& texturePair : textures) {
		delete texturePair.second;
	}
	textures.clear();
}
