// 程序入口点
// Created by Loturias on 25-2-4.

#include <Windows.h>
#include <iostream>

int WINAPI WinMain(
_In_ HINSTANCE hInstance,
_In_opt_ HINSTANCE hPrevInstance,
_In_ LPSTR lpCmdLine,
_In_ int nCmdShow )
{
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	freopen("CONIN$", "r", stdin);
	freopen("CONERR$", "w", stderr);

	std::cout << "Hello, World!" << std::endl;
	std::cout << "Press any key to exit..." << std::endl;
	std::cin.get();
	return 0;
}