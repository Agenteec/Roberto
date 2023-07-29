#include "Level.h"

bool Level::load(const std::string path)
{
	if (!map.load(path))
	{
		return false;
	}
    const auto& layers = map.getLayers();
    for (int i = 0; i < layers.size(); i++)
    {
        MapLayer* layer = new MapLayer(map, i);
        mapLayers.push_back(layer);
    }

	
}

void Level::update()
{
}

void Level::draw(sf::RenderWindow& window, const sf::Time& time)
{
}
