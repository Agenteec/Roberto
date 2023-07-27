#include <SFML/Graphics.hpp>
#include <tmxlite/Map.hpp>
#include "../include/SFMLOrthogonalLayer.hpp"
#include <vector>
#include <iostream>

struct WASD
{
    WASD() :
        wPressed(false),
        aPressed(false),
        sPressed(false),
        dPressed(false)
    {

    }
    bool wPressed;
    bool aPressed;
    bool sPressed;
    bool dPressed;
};
void moveSprite(const WASD& wasd, sf::Vector2f& sprite, const float& deltaTime, const float& speed)
{
    if (wasd.wPressed)
        sprite += sf::Vector2f(0, -1.f * deltaTime * speed);
    if (wasd.sPressed)
        sprite += sf::Vector2f(0, 1.f * deltaTime * speed);
    if (wasd.aPressed)
        sprite += sf::Vector2f(-1.f * deltaTime * speed, 0);
    if (wasd.dPressed)
        sprite += sf::Vector2f(1.f * deltaTime * speed, 0);
}
int main()
{
    WASD wasd;
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    //std::vector<tmx::Layer::Ptr> layers;
    sf::Texture t;
    t.loadFromFile("Resources/png/entitys/dog.png");
    sf::Sprite tt;
    tt.setTexture(t);
    tmx::Map map;
    std::string path = "Resources/maps/testMap.tmx";
    //path = "demo.tmx";
    if (!map.load(path))
    {
        window.draw(tt);
        window.display();
        std::cout << path << std::endl;
        system("pause");
        window.close();
        return EXIT_FAILURE;
    }
    //try
    //{
    //    
    //    if (!map.load("Resources/maps/testMap.tmx"))
    //    {
    //        std::cout << "Error load map" << std::endl;
    //    }
    //}
    //catch (const std::exception& e)
    //{
    //    std::cout << "Error load map:" << e.what() << std::endl;
    //}

    MapLayer layerZero(map, 0);
    MapLayer layerOne(map, 1);
    MapLayer layerTwo(map, 2);
    sf::View view(window.getDefaultView());
    sf::Vector2f pos = view.getCenter();
    sf::Clock globalClock;
    float zoom = 1.f;
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::W)
                    wasd.wPressed = true;
                if (event.key.code == sf::Keyboard::S)
                    wasd.sPressed = true;
                if (event.key.code == sf::Keyboard::A)
                    wasd.aPressed = true;
                if (event.key.code == sf::Keyboard::D)
                    wasd.dPressed = true;
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
            }
            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::W)
                    wasd.wPressed = false;
                if (event.key.code == sf::Keyboard::S)
                    wasd.sPressed = false;
                if (event.key.code == sf::Keyboard::A)
                    wasd.aPressed = false;
                if (event.key.code == sf::Keyboard::D)
                    wasd.dPressed = false;
            }
            if (event.type == sf::Event::MouseWheelScrolled)
            {
                std::cout<<event.mouseWheelScroll.delta <<std::endl;
            }
        }

        sf::Time duration = globalClock.restart();
        moveSprite(wasd, pos, duration.asSeconds(), 600.f);
        view.zoom();
        view.setCenter(view.getCenter() + (pos - view.getCenter()) * 100.f * duration.asSeconds());
        window.setView(view);
        layerZero.update(duration);
        window.clear(sf::Color::Black);
        window.draw(layerZero);
        window.draw(layerOne);
        window.draw(layerTwo);
        window.display();
    }

    return 0;
}
