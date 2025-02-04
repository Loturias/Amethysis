// 程序入口点
// Created by Loturias on 25-2-4.

#include "SharedHeaders.hpp"
#include <iostream>
#include "Utility/Console/Console.hpp"
#include "Core/AppFrame/AppFrame.hpp"

int WINAPI WinMain(
_In_ HINSTANCE hInstance,
_In_opt_ HINSTANCE hPrevInstance,
_In_ LPSTR lpCmdLine,
_In_ int nCmdShow )
{
	Amethysis::Utility::Console::ConsoleManager::initConsole();

	Amethysis::Core::App::AppFrame appFrame(hInstance);

	/*std::cout << "Press Any Key To Exit..." << std::endl;
	std::cin.get();*/
	return 0;
}