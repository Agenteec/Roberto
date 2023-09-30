#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 728), "Shader");
    window.setFramerateLimit(60);
    sf::Vector2f size(1280, 728);
    sf::Texture whiteTexture;
    whiteTexture.create(size.x, size.y);
    
    // Заполняем текстуру белым цветом
    sf::Image image;
    image.create(size.x, size.y, sf::Color::White);
    whiteTexture.update(image);

    sf::Sprite sprite;
    sprite.setTexture(whiteTexture);

    sf::Shader shader;
    if (!shader.loadFromFile("Resources/shaders/text.frag", sf::Shader::Fragment)) {
        return 1;
    }
    //shader.setUniform("resolution", sf::Vector2f(window.getSize()));

    shader.setUniform("resolution", sf::Vector2f(1280, 728));

    //shader.setUniform("surfacePosition", sf::Vector2f(640, 480));
    sf::Vector2f worldPosition;
    float animationTime = 0.0f;
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            // Преобразуем позицию мыши в координаты view
            worldPosition = window.mapPixelToCoords(mousePosition);
        }
        //window.clear(sf::Color::White);
        // Обновляем анимацию обломков
        animationTime += clock.restart().asSeconds();
        if (animationTime > 9999.0f) {
            animationTime = 0.0f; // Перезапускаем анимацию
        }
        //shader.setUniform("resolution", worldPosition);
        shader.setUniform("time", animationTime); // Обновление времени 

        window.draw(sprite, &shader);
        // Обновляем окно
        window.display();
    }

    return 0;
}
