#include "Gui.h"
#include <Windows.h>
//void GUI::MainMenu(Flags& flags, const sf::Vector2u& size)
//{
//	ImGui::SetNextWindowSize(ImVec2(size.x, size.y), ImGuiCond_FirstUseEver);
//	ImGui::SetNextWindowPos(ImVec2(0, 0));
//	ImGui::GetStyle().Colors[ImGuiCol_WindowBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.25f);
//	//ImGuiWindowFlags_NoBackground
//	if (ImGui::Begin(u8"Flappy Bird", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove)) {
//
//		if (ImGui::Button(u8"Локальная игра", ImVec2(200, 50))) { flags.onGame = 1; flags.onMainMenu = 0; }
//		ImGui::Spacing;
//		if (ImGui::Button(u8"Сетевая игра", ImVec2(200, 50)))
//		{
//			MessageBox(NULL, L"Пока сетевой режим не доступен...\n", L"", MB_OK | MB_ICONINFORMATION);
//		}
//		ImGui::Spacing;
//		if (ImGui::Button(u8"Настройки", ImVec2(200, 50))) { flags.onSettings = flags.onSettings ? 0 : 1; }
//		ImGui::Spacing;
//		if (ImGui::Button(u8"Тест", ImVec2(200, 50)))
//		{
//			flags.onMainMenu = 0;
//			flags.onTest = 1;
//		}
//		ImGui::Spacing;
//		if (ImGui::Button(u8"Выйти", ImVec2(200, 50))) { std::exit(0); }
//	}
//	ImGui::End();
//}
//
//void GUI::TestsMenu(Flags& flags, int& test)
//{
//	ImGui::Begin("Test Selector");
//
//	// Выдвигающийся список с разными элементами
//	if (ImGui::CollapsingHeader(u8"Выбор теста"))
//	{
//		if (ImGui::Selectable(u8"GT"))
//		{
//			test = 1;
//		}
//		if (ImGui::Selectable(u8"MT"))
//		{
//			test = 2;
//		}
//	}
//
//	ImGui::End();
//}
