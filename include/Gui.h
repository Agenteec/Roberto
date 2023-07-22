#pragma once

#include <cstdlib>
#include <SFML/Graphics.hpp>

struct Flags
{
	bool onGame;
	bool onMainMenu;
	bool onSettings;
	bool onTest;
	Flags() :
		onGame(false),
		onMainMenu(true),
		onSettings(false),
		onTest(false)
	{}
};
class GUI
{
public:
	static void MainMenu(Flags& flags, const sf::Vector2u& size);
	static void TestsMenu(Flags& flags, int& test);
};

