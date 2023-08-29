#include "GameMath.h"

float angleTwoPoints(sf::Vector2f point, sf::Vector2f point2)
{
	// ������������ ������ ����� ������ � ���������� ����
	sf::Vector2f direction = point2 - point;

	// ��������� ���� ����� �������� � ������������� ������������ ��� X
	float angle = std::atan2(direction.y, direction.x);

	// ��������� ���� �� �������� � �������
	angle = angle * (180 / 3.14159265);

	if (angle < 0) {
		angle += 360;
	}
	return angle;
}

