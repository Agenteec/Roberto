#include "Camera.h"

Camera::Camera(): 
	View(),
	trackingObject(nullptr),
	moveSpeed(2.f),
	zoomSpeed(2.f),
	targetZoom(1.f)
{

}

void Camera::setTracking(GameObject* trackingObject)
{
	this->trackingObject = trackingObject;
}

void Camera::update(const float& deltaTime, sf::RenderWindow& window)
{
	#pragma region ZOOM
	float currentZoom = getSize().x / window.getSize().x;

	float zoomDiff = targetZoom - currentZoom;

	if (std::abs(zoomDiff) <= 0.001f)
	{
		setSize(targetZoom * window.getSize().x, targetZoom * window.getSize().y);
	}
	else
	{
		float zoomStep = zoomDiff * zoomSpeed * deltaTime;
		zoom(1.0f + zoomStep);
	}
	#pragma endregion

	#pragma region Tracking
	sf::Vector2f targetPosition = trackingObject->getPosition();
	sf::Vector2f currentPosition = getCenter();
	sf::Vector2f newPosition = currentPosition + (targetPosition - currentPosition) * moveSpeed * deltaTime;
	setCenter(newPosition);
	#pragma endregion


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

