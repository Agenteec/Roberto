#pragma once

#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>

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
	GUI();
	void MainMenu(tgui::Gui& gui);
	void TestsMenu(int& test);
	void MainMenuInit(tgui::Gui& gui);
	void TestMenuInit(tgui::Gui& gui);
	Flags flags;
};

