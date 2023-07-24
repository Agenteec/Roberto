#include "Gui.h"
void GUI::MainMenuInit(tgui::Gui& gui)
{
	mainMenuWindow = tgui::Group::create();
	mainMenuWindow->setSize("100%", "100%");
	auto buttonLocalGame = tgui::Button::create(L"Локальная игра");
	buttonLocalGame->setPosition("25%", "15%");
	buttonLocalGame->setSize("50%", "10%");
	buttonLocalGame->onClick([&]() {
		flags.onGame = 1;
		flags.onMainMenu = 0;
		mainMenuWindow->setVisible(false);
		mainMenuWindow->setEnabled(false);
		});

	auto buttonNetworkGame = tgui::Button::create(L"Сетевая игра");
	buttonNetworkGame->setPosition("25%", "30%");
	buttonNetworkGame->setSize("50%", "10%");
	buttonNetworkGame->onClick ([&]() {
		flags.onGame = 1;
		flags.onMainMenu = 0;
		mainMenuWindow->setVisible(false);
		mainMenuWindow->setEnabled(false);
		});

	auto buttonSettings = tgui::Button::create(L"Настройки");
	buttonSettings->setPosition("25%", "45%");
	buttonSettings->setSize("50%", "10%");
	buttonSettings->onClick([&]() {
		flags.onSettings = !flags.onSettings;
		});

	auto buttonTest = tgui::Button::create(L"Тест");
	buttonTest->setPosition("25%", "60%");
	buttonTest->setSize("50%", "10%");
	buttonTest->onClick([&]() {
		flags.onMainMenu = 0;
		flags.onTest = 1;
		});

	auto buttonExit = tgui::Button::create(L"Выйти");
	buttonExit->setPosition("25%", "75%");
	buttonExit->setSize("50%", "10%");
	buttonExit->onClick([&]() {
		std::exit(0);
		});

	// Добавляем кнопки в окно
	mainMenuWindow->add(buttonLocalGame);
	mainMenuWindow->add(buttonNetworkGame);
	mainMenuWindow->add(buttonSettings);
	mainMenuWindow->add(buttonTest);
	mainMenuWindow->add(buttonExit);

	// Добавляем окно в GUI
	gui.add(mainMenuWindow);
}
GUI::GUI():
	flags()
{

}

void GUI::GameMenuInit(tgui::Gui& gui)
{
	
}

void GUI::SettingsMenu(tgui::Gui& gui)
{

}

void GUI::TestMenuInit(tgui::Gui& gui)
{

}

void GUI::MainMenu(tgui::Gui& gui)
{
		
}

void GUI::TestsMenu(int& test)
{

}
