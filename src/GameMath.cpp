#include "GameMath.h"

float angleTwoPoints(sf::Vector2f point, sf::Vector2f point2)
{
	// Рассчитываем вектор между точкой и положением мыши
	sf::Vector2f direction = point2 - point;

	// Вычисляем угол между вектором и положительным направлением оси X
	float angle = std::atan2(direction.y, direction.x);

	// Переводим угол из радианов в градусы
	angle = angle * (180 / 3.14159265);

	if (angle < 0) {
		angle += 360;
	}
	return angle;
}

