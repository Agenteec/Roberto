#pragma once
#define buildVersion "Alpha V(0.0.1)"

#include <SFML/Graphics.hpp>

#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>

#include "FeatureTester.h"
#include "Settings.h"
#include "GUI.h"


class MainWindow
{
private:
	sf::RenderWindow window;
	tgui::GuiSFML gui;
	GUI guiManager;
	FeatureTester test;
public:
	MainWindow();
	MainWindow(const Settings& settings);
	std::string GetBuildVersionString();
	void Display();
};
