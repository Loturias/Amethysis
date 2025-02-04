// 控制台管理
// Created by Loturias on 25-2-4.
//

#pragma once
#include <iostream>
#include <Windows.h>

namespace Amethysis::Utility::Console
{
	///@brief 控制台管理器
	struct ConsoleManager
	{
		///@brief 获取全局静态实例
		static ConsoleManager& getInstance()
		{
			static ConsoleManager instance;
			return instance;
		}

		// 禁止拷贝构造和赋值

		ConsoleManager(const ConsoleManager&) = delete;
		ConsoleManager& operator=(const ConsoleManager&) = delete;

		///@brief 初始化控制台
		static void initConsole();

		///@brief 关闭控制台
		void closeConsole();

	private:
		///@brief 构造函数，禁止外部实例化，仅允许单例模式
		ConsoleManager() = default;
		~ConsoleManager() = default;
	};

	inline void ConsoleManager::initConsole()
	{
		AllocConsole();
		freopen("CONOUT$", "w", stdout);
		freopen("CONIN$", "r", stdin);
		freopen("CONERR$", "w", stderr);
	}
}

