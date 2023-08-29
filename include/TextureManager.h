#pragma once
#include <SFML/Graphics.hpp>
/// <summary>
/// Менеджер текстур
/// </summary>
class TextureManager
{
public:
	/// <summary>
	/// Загрузка текстур из дисковой памяти в оперативную память
	/// </summary>
	/// <param name="textureList">Список путей к текстурам и их названия в игре</param>
	/// <param name="size">Размер списка</param>
	void loadTextures(std::pair<std::string, std::string> textureList[], const int& size);
	/// <summary>
	/// Список текстур в ОЗУ
	/// </summary>
	std::map<std::string, sf::Texture*> textures;
	/// <summary>
	/// Удаление текстур из оперативной памяти
	/// </summary>
	void clear();

};
