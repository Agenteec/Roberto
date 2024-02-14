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

	bool isGameInit;

	Flags() :
		onGame(false),
		onGameMenu(false),
		onMainMenu(true),
		onSettingsMenu(false),
		onTest(false),
		isGameInit(false)
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
	void GameMenuInit(auto& gui);
	void MainMenuInit(auto& gui);
	void SettingsMenuInit(auto& gui);
	void TestMenuInit(auto& gui);
	Flags flags;
	tgui::Group::Ptr mainMenuWindow;
	tgui::Group::Ptr gameMenuWindow;
	tgui::Group::Ptr settingsMenuWindow;
};

