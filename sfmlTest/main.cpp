#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(50, 80));
	rectangle.setOrigin(50/2, 80/2);
	rectangle.setPosition(640 / 2, 480 / 2);
	rectangle.setFillColor(sf::Color::Black);
	float i = 1;
	float seconds = 0;

	sf::RenderWindow window(sf::VideoMode(640, 480), L"ÁëÿÁîìáºçíî");
	sf::Clock clock;


	while (window.isOpen())
	{
		float deltaTime = clock.restart().asSeconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		seconds += deltaTime;
		if (seconds >= 0.01f)
		{
			seconds = 0;
			rectangle.setRotation(i);
			i++;
		}
		window.clear(sf::Color::Red);
		window.draw(rectangle);
		window.display();
	}

	return 0;
}