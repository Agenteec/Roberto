#pragma once

#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <vector>

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
	void SettingsMenu(tgui::Gui& gui);
	void GameMenu(tgui::Gui& gui);
	void MainMenu(tgui::Gui& gui);
	void TestsMenu(int& test);
	void GameMenuInit(tgui::Gui& gui);
	void MainMenuInit(tgui::Gui& gui);
	void TestMenuInit(tgui::Gui& gui);
	Flags flags;
	tgui::Group::Ptr mainMenuWindow;
};

