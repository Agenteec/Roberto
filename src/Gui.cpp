#include "Gui.h"
void GUI::MainMenuInit(tgui::Gui& gui)
{
	auto window = tgui::Group::create();
	window->setSize("100%", "100%");
	auto buttonLocalGame = tgui::Button::create(L"Локальная игра");
	buttonLocalGame->setPosition("25%", "15%");
	buttonLocalGame->setSize("50%", "10%");
	buttonLocalGame->onClick([&]() {
		flags.onGame = 1;
		flags.onMainMenu = 0;
		});

	auto buttonNetworkGame = tgui::Button::create(L"Сетевая игра");
	buttonNetworkGame->setPosition("25%", "30%");
	buttonNetworkGame->setSize("50%", "10%");
	buttonNetworkGame->onClick ([&]() {
		
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
	window->add(buttonLocalGame);
	window->add(buttonNetworkGame);
	window->add(buttonSettings);
	window->add(buttonTest);
	window->add(buttonExit);

	// Добавляем окно в GUI
	gui.add(window);
}
GUI::GUI():
	flags()
{

}
void GUI::MainMenu(tgui::Gui& gui)
{
		
}

void GUI::TestsMenu(int& test)
{

}
