#pragma once
#define buildVersion "Alpha V(0.0.5)"

#include <SFML/Graphics.hpp>

#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>

#include "FeatureTester.h"
#include "Settings.h"
#include "GUI.h"
#include "Game.h"
#include <TGUI/Widget.hpp>
class MainWindow
{
private:
	sf::RenderWindow window;
	tgui:: gui;
	GUI guiManager;
	FeatureTester test;
	Game game;
public:
	MainWindow();
	MainWindow(const Settings& settings);
	std::string GetBuildVersionString();
	void Display();
};
