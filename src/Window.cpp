#include "window.h"



MainWindow::MainWindow() :
	window(sf::VideoMode(800, 600), L"Roberto"),
	flags()
{
}

MainWindow::MainWindow(const Settings& settings) :
	window(settings.videoSettings.videoMode, "Roberto", (settings.videoSettings.fullscreen ? sf::Style::Fullscreen : sf::Style::Default), settings.videoSettings.сontext),
	flags()
{
}

std::string MainWindow::GetBuildVersionString()
{
#pragma region Время/Версия билда
	// получаем текущую дату и время
	std::time_t t = std::time(nullptr);
	std::tm tm;
	localtime_s(&tm, &t);
	std::stringstream ss;
	ss << buildVersion << " " << std::put_time(&tm, "%d.%m.%Y") << std::endl;
#pragma endregion
	return std::string();
}


void MainWindow::Display()
{
	sf::Clock clock;
	while (window.isOpen())
	{

		sf::Event event;

		while (window.pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		if (flags.onMainMenu)
		{
			GUI::MainMenu(flags, window.getSize());
		}
		if (flags.onTest)
		{
			GUI::TestsMenu(flags, test.testNumber);
		}
		test.TestSelector();
		window.clear(sf::Color(230, 230, 230, 255));
		window.display();

	}
}
