#include "window.h"

MainWindow::MainWindow() :
	window(sf::VideoMode(800, 600), L"Roberto")
{
	gui.setTarget(window);
}

MainWindow::MainWindow(const Settings& settings) :
	window(settings.videoSettings.videoMode, "Roberto", (settings.videoSettings.fullscreen ? sf::Style::Fullscreen : sf::Style::Default), settings.videoSettings.сontext)
{
	gui.setTarget(window);
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
	guiManager.MainMenuInit(gui);
	guiManager.GameMenuInit(gui);
	guiManager.SettingsMenuInit(gui);
	guiManager.flags.onMainMenu = true;
	
	sf::Clock clock;
	
	while (window.isOpen())
	{
		sf::Time deltaTime = clock.restart();
		sf::Event event;

		while (window.pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed)
				window.close();
			gui.handleEvent(event);
			if (guiManager.flags.onGame)
				game.handleEvent(event);

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{

					guiManager.MainMenu(false);
					guiManager.GameMenu(true);
					
				}
			}
		}

		if (guiManager.flags.onGame)
		{
			game.update(deltaTime, window);
			if (guiManager.flags.isGameInit)
			{
				game.init("Resources/maps/testMap.tmx");
				guiManager.flags.isGameInit = !guiManager.flags.isGameInit;
			}
		}
		if (guiManager.flags.onGameMenu)
		{
			guiManager.GameMenu(true);
		}
		if (guiManager.flags.onMainMenu)
		{
			guiManager.MainMenu(true);
		}
		if (guiManager.flags.onSettingsMenu)
		{
			guiManager.SettingsMenu(true);
		}
		if (guiManager.flags.onTest)
		{
			guiManager.TestsMenu(test.testNumber);
		}


		//test.TestSelector();
		window.clear(sf::Color(230, 230, 230, 255));
		gui.draw();

		if (guiManager.flags.onGame)
		{
			game.draw(window);
		}

		window.display();

	}
}
