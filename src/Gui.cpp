#include "Gui.h"

void GUI::MainMenuInit(tgui::Gui& gui)
{
	mainMenuWindow = tgui::Group::create();
	mainMenuWindow->setSize("100%", "100%");
	auto buttonLocalGame = tgui::Button::create(L"Локальная игра");
	buttonLocalGame->setPosition("25%", "15%");
	buttonLocalGame->setSize("50%", "10%");
	buttonLocalGame->onClick([&]() {
		MainMenu(false);
		flags.onGame = 1;
		});

	auto buttonNetworkGame = tgui::Button::create(L"Сетевая игра");
	buttonNetworkGame->setPosition("25%", "30%");
	buttonNetworkGame->setSize("50%", "10%");
	buttonNetworkGame->onClick ([&]() {
		MainMenu(false);
		flags.onGame = 1;
		});

	auto buttonSettings = tgui::Button::create(L"Настройки");
	buttonSettings->setPosition("25%", "45%");
	buttonSettings->setSize("50%", "10%");
	buttonSettings->onClick([&]() {
		MainMenu(false);
		flags.onSettingsMenu = true;
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
	gameMenuWindow = tgui::Group::create();
	gameMenuWindow->setSize("100%", "100%");

	auto buttonResumeGame = tgui::Button::create(L"Продолжить");
	buttonResumeGame->setPosition("25%", "35%");
	buttonResumeGame->setSize("50%", "10%");
	buttonResumeGame->onClick([&]() {
		GameMenu(false);
		flags.onGame = 1;
		});

	auto buttonExitToMainMenu = tgui::Button::create(L"Выйти в главное меню");
	buttonExitToMainMenu->setPosition("25%", "50%");
	buttonExitToMainMenu->setSize("50%", "10%");
	buttonExitToMainMenu->onClick([&]() {
		GameMenu(false);
		flags.onGame = 0;
		MainMenu(true);
		});

	auto buttonExit = tgui::Button::create(L"Выйти из игры");
	buttonExit->setPosition("25%", "65%");
	buttonExit->setSize("50%", "10%");
	buttonExit->onClick([&]() {
		std::exit(0);
		});

	GameMenu(false);

	gameMenuWindow->add(buttonResumeGame);
	gameMenuWindow->add(buttonExitToMainMenu);
	gameMenuWindow->add(buttonExit);

	gui.add(gameMenuWindow);
}

void GUI::SettingsMenuInit(tgui::Gui& gui)
{
	settingsMenuWindow = tgui::Group::create();
	settingsMenuWindow->setSize("100%", "100%");
	
	auto tabContainer = tgui::TabContainer::create();
	auto VideoSettings = tabContainer->addTab(L"Видео");
	auto AudioSettings = tabContainer->addTab(L"Аудио");
	auto KeyboardSettings = tabContainer->addTab(L"Клавиатура");
	auto MouseSettings = tabContainer->addTab(L"Мышь");

	tabContainer->setPosition("5%", "0%");
	tabContainer->setTabsHeight(30);
	tabContainer->setSize("95%", "95%");

	auto videoSettingsGroup = tgui::Group::create();
	VideoSettings->add(videoSettingsGroup);

	auto audioSettingsGroup = tgui::Group::create();
	AudioSettings->add(audioSettingsGroup);

	auto keyboardSettingsGroup = tgui::Group::create();
	KeyboardSettings->add(keyboardSettingsGroup);

	auto mouseSettingsGroup = tgui::Group::create();
	MouseSettings->add(mouseSettingsGroup);

	auto buttonReturn = tgui::Button::create(L"Назад");
	buttonReturn->setPosition("5%", "91%");
	buttonReturn->setSize("15%", "5%");
	buttonReturn->onClick([&]() {
		SettingsMenu(false);
		MainMenu(true);
		});

	auto buttonSave = tgui::Button::create(L"Применить");
	buttonSave->setPosition("64%", "91%");
	buttonSave->setSize("15%", "5%");
	buttonSave->onClick([&]() {
		
		});

	auto buttonCancel = tgui::Button::create(L"Отмена");
	buttonCancel->setPosition("80%", "91%");
	buttonCancel->setSize("15%", "5%");
	buttonCancel->onClick([&]() {

		});

	tabContainer->select(0);
	
	settingsMenuWindow->add(tabContainer);
	settingsMenuWindow->add(buttonReturn);
	settingsMenuWindow->add(buttonSave);
	settingsMenuWindow->add(buttonCancel);

	SettingsMenu(false);

	gui.add(settingsMenuWindow);
}

void GUI::GameMenu(const bool& flag)
{
	gameMenuWindow->setVisible(flag);
	gameMenuWindow->setEnabled(flag);
	flags.onGameMenu = flag;
}

void GUI::SettingsMenu(const bool& flag)
{
	settingsMenuWindow->setVisible(flag);
	settingsMenuWindow->setEnabled(flag);
	flags.onSettingsMenu = flag;
}

void GUI::TestMenuInit(tgui::Gui& gui)
{

}

void GUI::MainMenu(const bool& flag)
{
	mainMenuWindow->setVisible(flag);
	mainMenuWindow->setEnabled(flag);
	flags.onMainMenu = flag;
}

void GUI::TestsMenu(int& test)
{

}
