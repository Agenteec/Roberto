#include "Level.h"

bool Level::load(const std::string& path)
{
	if (!map.load(path))
	{
		return false;
	}

	const auto& layers = map.getLayers();
	std::cout << "Layers size:" << layers.size() << std::endl;
	for (int i = 0; i < layers.size(); i++)
	{
		MapLayer* layer = new MapLayer(map, i);
		mapLayers.push_back(layer);
	}
	return true;
	
}

void Level::update(const sf::Time& time)
{
	for (MapLayer* layer : mapLayers)
	{
		layer->update(time);
	}
}

void Level::draw(sf::RenderWindow& window)
{
	for (MapLayer* layer : mapLayers)
	{  
		window.draw(*layer);
	}
}
