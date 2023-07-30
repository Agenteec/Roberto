// Roberto.cpp: определяет точку входа для приложения.
//

#include "Roberto.h"

int main()
{
    Settings settings;
    settings.LoadFromJson();
    settings.SaveFromJson();
    std::cout << settings << std::endl;
    MainWindow* window = new MainWindow(settings);

    window->Display();

}