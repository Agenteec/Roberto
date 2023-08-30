//HeadsUpDisplay.h
#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
namespace HUD
{
	enum HUDType
	{
		FpsType,
		HealthPointType,
		Ammotype,
	};
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
}
