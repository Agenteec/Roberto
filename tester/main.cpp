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
    sf::Font font;
    font.loadFromFile("Resources/fonts/impact.ttf");
    sf::Text fpsText;
    fpsText.setFont(font);
    fpsText.setCharacterSize(24);
    fpsText.setFillColor(sf::Color::Green);
    fpsText.setPosition(10, 10);
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
        system("pause");
        window.close();
        return EXIT_FAILURE;
    }

    const auto& layers = map.getLayers();
    std::cout << "Layers size:" << layers.size() << std::endl;
    //std::vector<MapLayer> mapLayers;
    //for (size_t i = 0; i < layers.size()-1; i++)
    //{
    //    mapLayers.push_back(MapLayer(map, i));
    //}
    MapLayer l0(map, 0);
    MapLayer l1(map, 1);
    MapLayer l2(map, 2);
    sf::View view(window.getDefaultView());
    sf::Vector2f pos = view.getCenter();
    float targetZoom = 1.f;
    float zoomSpeed = 5.f;
    float elapsedTime = 0.f;
    int frames = 0;
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Time deltaTime = clock.restart();
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
                float temp = targetZoom;
                targetZoom -= static_cast<float>(event.mouseWheelScroll.delta) / 10.f;
                if (targetZoom<=0.1f || targetZoom >= 5)
                {
                    targetZoom = temp;
                }
            }
        }

        
        moveSprite(wasd, pos, deltaTime.asSeconds(), 600.f);
        #pragma region ZOOM
        float currentZoom = view.getSize().x / window.getSize().x;

        float zoomDiff = targetZoom - currentZoom;

        if (std::abs(zoomDiff) <= 0.001f)
        {
            view.setSize(targetZoom * window.getSize().x, targetZoom * window.getSize().y);
        }
        else
        {
            float zoomStep = zoomDiff * zoomSpeed * deltaTime.asSeconds();
            view.zoom(1.0f + zoomStep);
        }
        #pragma endregion

        view.setCenter(view.getCenter() + (pos - view.getCenter()) * 30.f * deltaTime.asSeconds()*targetZoom);
        //fpsText.setPosition(view.getCenter().x + 200, view.getCenter().y - 150);
        sf::Vector2f viewSize = view.getSize();
        sf::Vector2f viewCenter = view.getCenter();

        sf::Vector2f screenPos = sf::Vector2f(window.getSize().x - fpsText.getLocalBounds().width - 10, 10);
        sf::Vector2f worldPos = window.mapPixelToCoords(sf::Vector2i(screenPos), view);

        fpsText.setPosition(worldPos);
        window.setView(view);
        elapsedTime += deltaTime.asSeconds();
        fpsText.setScale(view.getSize().x / window.getSize().x, view.getSize().x / window.getSize().x);
        frames++;
        if (elapsedTime >= 1.0f) {
            float fps = frames / elapsedTime;
            fpsText.setString("FPS: " + std::to_string(static_cast<int>(fps)));
            frames = 0;
            elapsedTime = 0;

        }
        window.clear(sf::Color(200,200,255));
        //for (size_t i = 0; i < mapLayers.size(); i++)
        //{
        //    //mapLayers[i].update(deltaTime);
        //    window.draw(mapLayers[i]);

        //}

        l0.update(deltaTime);
        window.draw(l0);
        window.draw(l1);
        window.draw(l2);
        window.draw(fpsText);
        window.display();
    }

    return 0;
}
