#include "Animation.h"

void Animation::setTexture(sf::Texture* texture, int size)
{
	this->texture = texture;
	this->size = size;
}

void Animation::setTileSize(sf::Vector2f tileSize)
{
	this->tileSize = tileSize;
}

void Animation::setPosition(sf::Vector2f position)
{
	this->position = position;
}

void Animation::setFrameChangeTime(float length)
{
	this->frameChangeTime = length;
}

void Animation::setSize(int size)
{
	this->size = size;
}

sf::Texture* Animation::getTexture()
{
	return texture;
}

sf::Vector2f Animation::getTileSize()
{
	return tileSize;
}

sf::Vector2f Animation::getPosition()
{
	return position;
}

float Animation::getFrameChangeTime()
{
	return frameChangeTime;
}

int Animation::getSize()
{
	return size;
}


