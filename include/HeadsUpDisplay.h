//HeadsUpDisplay.h
#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
namespace HUD
{
	enum HUDType
	{
		FpsType,
		HealthPointType,
		Ammotype,
	};
	struct Lable 
	{
		HUDType type;
		sf::Text text;
		/// <summary>
		/// от 0 до 2
		/// </summary>
		sf::Vector2f positionCoefficient;
	};
	class HeadsUpDisplay
	{

	public:
		std::vector<Lable> labels;
		sf::Font font;
		HeadsUpDisplay()
		{
			if (!font.loadFromFile("Resources/fonts/impact.ttf"))
			{
				std::cout << "Error load font!" << std::endl;
			}
			//fpsText.setFont(font);
			/*fpsText.setString(L"");
			fpsText.setCharacterSize(30);
			fpsText.setFillColor(sf::Color::Green);
			fpsText.setPosition(1000, 1000);*/

		}
		void draw(sf::RenderWindow& window)
		{
			for(auto lable :labels)
			{
				window.draw(lable.text);
			}
		}

	};
}
