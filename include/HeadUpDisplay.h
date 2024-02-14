//HeadUpDisplay.h
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
		AmmoType,
	};
	struct Label 
	{
		HUDType type;
		sf::Text text;
		/// <summary>
		/// от 0 до 2
		/// </summary>
		sf::Vector2f positionCoefficient;
	};
	class HeadUpDisplay
	{

	public:
		std::vector<Label> labels;
		HeadUpDisplay()
		{
		}
		void draw(sf::RenderWindow& window)
		{
			for(auto label :labels)
			{
				window.draw(label.text);
			}
		}

	};
}
