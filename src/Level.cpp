#include "Level.h"


bool Level::load(const std::string& path)
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

void Level::parse(std::vector<GameObject*>& gameObjects, TextureManager* textureManager, b2World& world)
{
	const auto& layers = map.getLayers();
#pragma region Parse
	const std::array<std::string, 4u> LayerStrings =
	{
		std::string("Tile"),
		std::string("Object"),
		std::string("Image"),
		std::string("Group"),
	};
	std::cout << "Loaded Map version: " << map.getVersion().upper << ", " << map.getVersion().lower << std::endl;
	if (map.isInfinite())
	{
		std::cout << "Map is infinite.\n";
	}
	else
	{
		std::cout << "Map Dimensions: " << map.getBounds() << std::endl;
	}

	const auto& mapProperties = map.getProperties();
	std::cout << "Map class: " << map.getClass() << std::endl;

	std::cout << "Map tileset has " << map.getTilesets().size() << " tilesets" << std::endl;
	for (const auto& tileset : map.getTilesets())
	{
		std::cout << "Tileset: " << tileset.getName() << std::endl;
		std::cout << "Tileset class: " << tileset.getClass() << std::endl;
	}

	std::cout << "Map has " << mapProperties.size() << " properties" << std::endl;
	for (const auto& prop : mapProperties)
	{
		std::cout << "Found property: " << prop.getName() << std::endl;
		std::cout << "Type: " << int(prop.getType()) << std::endl;
	}

	std::cout << std::endl;


	std::cout << "Map has " << layers.size() << " layers" << std::endl;
	for (const auto& layer : layers)
	{
		std::cout << "Found Layer: " << layer->getName() << std::endl;
		std::cout << "Layer Type: " << LayerStrings[static_cast<std::int32_t>(layer->getType())] << std::endl;
		std::cout << "Layer Dimensions: " << layer->getSize() << std::endl;
		std::cout << "Layer Tint: " << layer->getTintColour() << std::endl;

		if (layer->getType() == tmx::Layer::Type::Group)
		{
			std::cout << "Checking sublayers" << std::endl;
			const auto& sublayers = layer->getLayerAs<tmx::LayerGroup>().getLayers();
			std::cout << "LayerGroup has " << sublayers.size() << " layers" << std::endl;
			for (const auto& sublayer : sublayers)
			{
				std::cout << "Found Layer: " << sublayer->getName() << std::endl;
				std::cout << "Sub-layer Type: " << LayerStrings[static_cast<std::int32_t>(sublayer->getType())] << std::endl;
				std::cout << "Sub-layer Class: " << sublayer->getClass() << std::endl;
				std::cout << "Sub-layer Dimensions: " << sublayer->getSize() << std::endl;
				std::cout << "Sub-layer Tint: " << sublayer->getTintColour() << std::endl;

				if (sublayer->getType() == tmx::Layer::Type::Object)
				{
					std::cout << sublayer->getName() << " has " << sublayer->getLayerAs<tmx::ObjectGroup>().getObjects().size() << " objects" << std::endl;
				}
				else if (sublayer->getType() == tmx::Layer::Type::Tile)
				{
					std::cout << sublayer->getName() << " has " << sublayer->getLayerAs<tmx::TileLayer>().getTiles().size() << " tiles" << std::endl;
				}
			}
		}

		if (layer->getType() == tmx::Layer::Type::Object)
		{
			const auto& objects = layer->getLayerAs<tmx::ObjectGroup>().getObjects();
			std::cout << "Found " << objects.size() << " objects in layer" << std::endl;
			for (const auto& object : objects)
			{
				if (object.getName() == "spawnPoint" && object.getClass() == "player")
				{
					playerSpawn.push_back(sf::Vector2f(object.getPosition().x, object.getPosition().y));
				}
				if (object.getClass() == "dynamic")
				{
					if (textureManager->textures.contains(object.getName()))
					{
						const auto& properties = object.getProperties();
						
						float density = -1.f;
						float friction = -1.f;
						float restitution = -1.f;
						for (const auto& prop : properties)
						{
							std::string propName = prop.getName();
							if (propName == "density")
								density = prop.getFloatValue();
							if (propName == "restitution")
								restitution = prop.getFloatValue();
							if (propName == "friction")
								friction = prop.getFloatValue();
						}

						Entity* entity = new Entity();
						entity->setTexture(*textureManager->textures[object.getName()]);
						sf::Vector2f scale = sf::Vector2f(object.getAABB().width / entity->getLocalBounds().width, object.getAABB().height / entity->getLocalBounds().height);
						entity->setScale(scale);
						entity->setOrigin(sf::Vector2f(entity->getLocalBounds().width / 2.f, entity->getLocalBounds().height / 2.f));
						entity->initBody(&world, sf::Vector2f(object.getPosition().x + entity->getLocalBounds().width* scale.x / 2.f, object.getPosition().y - entity->getLocalBounds().height * scale.y / 2.f), object.getRotation());
						entity->setBodyBoxShape(sf::Vector2f(entity->getLocalBounds().width, entity->getLocalBounds().height), density<0.f?1.f:density );//if(density < 0) density = 1.f; else density = customDensity
						if (density >= 0.f && friction >= 0.f && restitution >= 0)
						{
							entity->setPhysicalProperties(density, friction, restitution);
						}
						
						gameObjects.push_back(entity);
					}
				}
				if (object.getClass() == "static")
				{
					//std::cout << "----------------------------------------------------------------------\n";
					if (textureManager->textures.contains(object.getName()))
					{
						if (object.getName() == "wall0")
						{
							const auto& properties = object.getProperties();
							float density = -1.f;
							float friction = -1.f;
							float restitution = -1.f;
							for (const auto& prop : properties)
							{
								std::string propName = prop.getName();
								if (propName == "density")
									density = prop.getFloatValue();
								if (propName == "restitution")
									restitution = prop.getFloatValue();
								if (propName == "friction")
									friction = prop.getFloatValue();
							}
							float angle = 0.f;//radian
							Entity* wall = new Entity();
							wall->setTexture(*textureManager->textures[object.getName()]);
							wall->setOrigin(wall->getLocalBounds().width / 2.f, wall->getLocalBounds().height / 2.f);
							sf::Vector2f scale = sf::Vector2f(object.getAABB().width/ wall->getLocalBounds().width, object.getAABB().height / wall->getLocalBounds().height);
							wall->setScale(scale);
							wall->initBody(&world, sf::Vector2f(object.getPosition().x + object.getAABB().width / 2.f, object.getPosition().y + object.getAABB().height / 2.f),0.f, b2_staticBody);
							std::wcout <<"Wall local bonus: "<< wall->getLocalBounds().width << std::endl;
							wall->setBodyBoxShape(sf::Vector2f(wall->getLocalBounds().width, wall->getLocalBounds().height), density < 0.f ? 1.f : density);
							//wall->body->SetTransform(b2Vec2(object.getPosition().x*2 / GlobalConsts::SCALE, object.getPosition().y*2/ GlobalConsts::SCALE), angle);
							gameObjects.push_back(wall);
						}
					}
				}
				

				if (!object.getTilesetName().empty())
				{
					std::cout << "Object uses template tile set " << object.getTilesetName() << "\n";
				}
			}
		}

		if (layer->getType() == tmx::Layer::Type::Tile)
		{
			const auto& tiles = layer->getLayerAs<tmx::TileLayer>().getTiles();
			if (tiles.empty())
			{
				const auto& chunks = layer->getLayerAs<tmx::TileLayer>().getChunks();
				if (chunks.empty())
				{
					std::cout << "Layer has missing tile data\n";
				}
				else
				{
					std::cout << "Layer has " << chunks.size() << " tile chunks.\n";
				}
			}
			else
			{
				std::cout << "Layer has " << tiles.size() << " tiles.\n";
			}
		}

		const auto& properties = layer->getProperties();
		std::cout << properties.size() << " Layer Properties:" << std::endl;
		for (const auto& prop : properties)
		{
			std::cout << "Found property: " << prop.getName() << std::endl;
			std::cout << "Type: " << int(prop.getType()) << std::endl;
		}
	}
#pragma endregion
}
