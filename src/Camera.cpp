#include "Camera.h"

Camera::Camera(): 
	View(),
	trackingObject(nullptr),
	moveSpeed(2.f),
	zoomSpeed(2.5f),
	targetZoom(1.4f),
	headsUpDisplay()
{

}

void Camera::setTracking(GameObject* trackingObject)
{
	this->trackingObject = trackingObject;
}

void Camera::update(const sf::Time& deltaTime, sf::RenderWindow& window)
{
	float dts = deltaTime.asSeconds();
	headsUpDisplay.fpsText.setString("FPS: " + std::to_string(static_cast<int>(1.f/dts)));
	#pragma region ZOOM
	float currentZoom = getSize().x / window.getSize().x;
	
	float zoomDiff = targetZoom - currentZoom;

	if (std::abs(zoomDiff) <= 0.01f)
	{
		setSize(targetZoom * window.getSize().x, targetZoom * window.getSize().y);
	}
	else
	{
		float zoomStep = zoomDiff * zoomSpeed * dts;
		zoom(1.0f + zoomStep);
	}
	#pragma endregion

	#pragma region Tracking
	if (trackingObject != nullptr)
	{
		sf::Vector2f targetPosition = trackingObject->getPosition();
		sf::Vector2f currentPosition = getCenter();
		sf::Vector2f newPosition = currentPosition + (targetPosition - currentPosition) * moveSpeed * dts;
		setCenter(newPosition);
	}
	#pragma endregion
	headsUpDisplay.fpsText.setPosition(this->getCenter().x + 400, this->getCenter().y - 350);
	headsUpDisplay.draw(window);
	window.setView(*this);
	
}

void Camera::setMoveSpeed(const float& speed)
{
	this->moveSpeed = speed;
}

const float& Camera::getMoveSpeed()
{
	return moveSpeed;
}

void Camera::setZoomSpeed(const float& speed)
{
	zoomSpeed = speed;
}

const float& Camera::getZoomSpeed()
{
	return zoomSpeed;
}

void Camera::setTargetZoom(const float& targetZoom)
{
	this->targetZoom = targetZoom;
}

const float& Camera::getTargetZoom()
{
	return targetZoom;
}


