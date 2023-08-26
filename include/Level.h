#pragma once
#include <box2d/box2d.h>
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

/// <summary>
/// Игровой уровень
/// </summary>
class Level
{


public:
	/// <summary>
	/// Объект для хранения карты xml
	/// </summary>
	tmx::Map map;
	/// <summary>
	/// Вектор для извлечения слоёв
	/// </summary>
	std::vector<MapLayer*> mapLayers;
	/// <summary>
	/// Загрузка xml файла с картой через путь
	/// Заполняет объект map
	/// </summary>
	/// <param name="path">Путь к карте</param>
	/// <returns></returns>
	bool load(const std::string& path);
	/// <summary>
	/// Обновление порядка анимаций и тригерных зон...
	/// </summary>
	/// <param name="time">delta time</param>
	void update(const sf::Time& time);
	/// <summary>
	/// Отрисовка всех тайлов(кроме тел box2d) на экране
	/// </summary>
	/// <param name="window"></param>
	void draw(sf::RenderWindow& window);
	/// <summary>
	/// Извлечение всех объектов из слоёв, создание тел box2d реализация тригеров и т.д.
	/// </summary>
	/// <param name="gameObjects">Вектор со всеми игровыми объектами</param>
	/// <param name="textureManager">Объект с названиями текстур</param>
	/// <param name="world">Мир box2d</param>
	void parse(std::vector<GameObject*>& gameObjects, TextureManager* textureManager, b2World& world);
	/// <summary>
	/// Координаты появления игроков
	/// </summary>
	std::vector<sf::Vector2f> playerSpawn;
};