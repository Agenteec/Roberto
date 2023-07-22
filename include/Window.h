#pragma once
#define buildVersion "Alpha V(0.0.1)"

#include <SFML/Graphics.hpp>

#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>

class Window
{
public:
	Window();
	~Window();
	std::string GetBuildVersionString();
	
private:
	sf::RenderWindow window;
};

Window::Window()
{
}

Window::~Window()
{
}