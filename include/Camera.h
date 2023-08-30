//Camera.h
#include <sfml/Graphics.hpp>
#include <iostream>
#include "GameObject.h"
//Не работающий HUD
class HeadsUpDisplay
{
	
public:
	sf::Font font;
	sf::Text fpsText;
	HeadsUpDisplay()
	{
		if (!font.loadFromFile("Resources/fonts/impact.ttf"))
		{
			std::cout << "Error load font!" << std::endl;
		}
		fpsText.setFont(font);
		fpsText.setString(L"");
		fpsText.setCharacterSize(30);
		fpsText.setFillColor(sf::Color::Green);
		fpsText.setPosition(1000, 1000);

	}
	void draw(sf::RenderWindow& window)
	{
		
		window.draw(fpsText);
	}

};
class Camera : public sf::View
{
	float moveSpeed;
	float zoomSpeed;
	float targetZoom;
	GameObject* trackingObject;
	HeadsUpDisplay headsUpDisplay;
	sf::RectangleShape blind;


	void updateHUD(const float& dts, sf::RenderWindow& window);

public:
	Camera();

	void setTracking(GameObject* trackingObject);

	void update(const sf::Time& deltaTime, sf::RenderWindow& window);


	void draw(sf::RenderWindow& window);

	void setMoveSpeed(const float& speed);

	const float& getMoveSpeed();

	void setZoomSpeed(const float& speed);

	const float& getZoomSpeed();

	void setTargetZoom(const float& targetZoom);

	const float& getTargetZoom();

};