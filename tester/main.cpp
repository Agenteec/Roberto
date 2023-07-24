//#include <SFML/Graphics.hpp>
//#include <tmxlite/Map.hpp>
//#include <tmxlite/TileLayer.hpp>
//#include <iostream>
//
//int main()
//{
//    // �������� ����� Tiled �� �����
//    tmx::Map map;
//    if (!map.load("Resources/maps/TestMap.tmx"))
//    {
//        std::cout << "Error loading map." << std::endl;
//        return 1;
//    }
//
//    // ����������� ������� ������
//    unsigned int tileWidth = map.getTileSize().x;
//    unsigned int tileHeight = map.getTileSize().y;
//
//    // �������� ���� ��� ����������� �����
//    sf::RenderWindow window(sf::VideoMode(map.getTileCount().x * tileWidth, map.getTileCount().y * tileHeight), "Tiled Map with tmxlite and SFML");
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//
//        // ����������� ������ �� ������
//        for (const auto& layer : map.getLayers())
//        {
//            if (layer->getType() == tmx::Layer::Type::Tile)
//            {
//                const tmx::TileLayer* tileLayer = dynamic_cast<const tmx::TileLayer*>(layer.get());
//
//                for (int y = 0; y < tileLayer->getSize().y; ++y)
//                {
//                    for (int x = 0; x < tileLayer->getSize().x; ++x)
//                    {
//                        int tileID = tileLayer->getTileTilesetIndex(x, y);
//                        if (tileID != 0) // ���������� ������ �����
//                        {
//                            const sf::Texture& texture = tileLayer->getTileTileset(tileID).getImage().getTexture();
//                            sf::Sprite sprite;
//                            sprite.setTexture(texture);
//                            sprite.setTextureRect(tileLayer->getTileTileset(tileID).getTileRect(tileID));
//                            sprite.setPosition(x * tileWidth, y * tileHeight);
//
//                            window.draw(sprite);
//                        }
//                    }
//                }
//            }
//        }
//
//        window.display();
//    }
//
//    return 0;
//}
