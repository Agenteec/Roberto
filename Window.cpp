#include "window.h"

std::string Window::GetBuildVersionString()
{
	#pragma region Время/Версия билда
	// получаем текущую дату и время
	std::time_t t = std::time(nullptr);
	std::tm tm;
	localtime_s(&tm, &t);
	std::stringstream ss;
	ss << buildVersion << " " << std::put_time(&tm, "%d.%m.%Y") << std::endl;
	#pragma endregion
	return std::string();
}
