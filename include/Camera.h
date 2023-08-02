//Camera.h
#include <sfml/Graphics.hpp>
#include "GameObject.h"
class Camera : public sf::View
{
	float moveSpeed;
	float zoomSpeed;
	float targetZoom;
	sf::
	GameObject* trackingObject;
	sf::RectangleShape blind;
public:
	Camera();

	void setTracking(GameObject* trackingObject);

	void update(const sf::Time& deltaTime, sf::RenderWindow& window);

	void setMoveSpeed(const float& speed);

	const float& getMoveSpeed();

	void setZoomSpeed(const float& speed);

	const float& getZoomSpeed();

	void setTargetZoom(const float& targetZoom);

	const float& getTargetZoom();







};