#pragma once

#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <vector>

struct Flags
{
	bool onGame;
	bool onGameMenu;
	bool onMainMenu;
	bool onSettingsMenu;
	bool onTest;
	Flags() :
		onGame(false),
		onGameMenu(false),
		onMainMenu(true),
		onSettingsMenu(false),
		onTest(false)
	{}
};
class GUI
{


public:
	GUI();
	void SettingsMenu(const bool& flag);
	void GameMenu(const bool& flag);
	void MainMenu(const bool& flag);
	void TestsMenu(int& test);
	void GameMenuInit(tgui::Gui& gui);
	void MainMenuInit(tgui::Gui& gui);
	void SettingsMenuInit(tgui::Gui& gui);
	void TestMenuInit(tgui::Gui& gui);
	Flags flags;
	tgui::Group::Ptr mainMenuWindow;
	tgui::Group::Ptr gameMenuWindow;
	tgui::Group::Ptr settingsMenuWindow;
};

