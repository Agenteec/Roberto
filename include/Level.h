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
/// ������� �������
/// </summary>
class Level
{


public:
	/// <summary>
	/// ������ ��� �������� ����� xml
	/// </summary>
	tmx::Map map;
	/// <summary>
	/// ������ ��� ���������� ����
	/// </summary>
	std::vector<MapLayer*> mapLayers;
	/// <summary>
	/// �������� xml ����� � ������ ����� ����
	/// ��������� ������ map
	/// </summary>
	/// <param name="path">���� � �����</param>
	/// <returns></returns>
	bool load(const std::string& path);
	/// <summary>
	/// ���������� ������� �������� � ��������� ���...
	/// </summary>
	/// <param name="time">delta time</param>
	void update(const sf::Time& time);
	/// <summary>
	/// ��������� ���� ������(����� ��� box2d) �� ������
	/// </summary>
	/// <param name="window"></param>
	void draw(sf::RenderWindow& window);
	/// <summary>
	/// ���������� ���� �������� �� ����, �������� ��� box2d ���������� �������� � �.�.
	/// </summary>
	/// <param name="gameObjects">������ �� ����� �������� ���������</param>
	/// <param name="textureManager">������ � ���������� �������</param>
	/// <param name="world">��� box2d</param>
	void parse(std::vector<GameObject*>& gameObjects, TextureManager* textureManager, b2World& world);
	/// <summary>
	/// ���������� ��������� �������
	/// </summary>
	std::vector<sf::Vector2f> playerSpawn;
};