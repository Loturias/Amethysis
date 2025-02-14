// LuaEngine的接口实现
// Created by Loturias on 25-2-13.
//

#include "Application.hpp"

namespace Amethysis::Core::App {
	void Application::onLuaEngineCreate()
	{
		setLuaState(luaL_newstate());
		if (!getLuaState())
		{
			// 创建Lua虚拟机失败
			spdlog::error("Create Lua Virtual Machine Failed.");
			throw std::runtime_error("Create Lua Virtual Machine Failed.");
		}

		spdlog::info("Lua Virtual Machine Initialized.");

		// 加载标准库
		luaL_openlibs(getLuaState());

	}

	void Application::onLuaEngineDestroy()
	{
		// 关闭Lua虚拟机
		if (getLuaState())
		{
			lua_close(getLuaState());
			spdlog::info("Lua Virtual Machine Destroyed.");
			setLuaState(nullptr);
		}
	}
}