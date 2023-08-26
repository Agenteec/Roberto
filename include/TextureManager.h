#pragma once
#include <SFML/Graphics.hpp>
/// <summary>
/// �������� �������
/// </summary>
class TextureManager
{
public:
	/// <summary>
	/// �������� ������� �� �������� ������ � ����������� ������
	/// </summary>
	/// <param name="textureList">������ ����� � ��������� � �� �������� � ����</param>
	/// <param name="size">������ ������</param>
	void loadTextures(std::pair<std::string, std::string> textureList[], const int& size);
	/// <summary>
	/// ������ ������� � ���
	/// </summary>
	std::map<std::string, sf::Texture*> textures;
	/// <summary>
	/// �������� ������� �� ����������� ������
	/// </summary>
	void clear();

};
