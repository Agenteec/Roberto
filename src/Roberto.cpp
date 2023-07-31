// Roberto.cpp: определяет точку входа для приложения.
//

#include "Roberto.h"

int main(int argc, char** argv)
{
    if (argc == 1) { // если в аргументах только имя программы
        std::cout << "no arguments!" << std::endl; // выводим, что нет аргументов
    }
    else {
        // иначе выводим все аргументы, которые переданы
        for (int i = 1; i < argc; i++) {
            std::cout << "argv[" << i << "] - " << argv[i] << std::endl;
        }
    }


    Settings settings;
    settings.LoadFromJson();
    settings.SaveFromJson();
    std::cout << settings << std::endl;
    MainWindow* window = new MainWindow(settings);
    window->Display();

}