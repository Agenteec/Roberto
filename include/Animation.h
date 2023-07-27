#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
public:
	Animation();

	void setTexture(sf::Texture* texture, int size);
	void setTileSize(sf::Vector2f tileSize);
	void setPosition(sf::Vector2f position);
	void setFrameChangeTime(float length);
	void setSize(int size);

	sf::Texture* getTexture();
	sf::Vector2f getTileSize();
	sf::Vector2f getPosition();
	float getFrameChangeTime();
	int getSize();

	void play();

private:
	sf::Texture* texture;
	sf::Vector2f tileSize;
	sf::Vector2f position;
	float frameChangeTime;
	int size;
};