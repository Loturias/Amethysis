// AppFrame类的LuaEngine部分实现
// Created by Loturias on 25-2-13.
//

#include "AppFrame.hpp"

namespace Amethysis::Core::App {
	void AppFrame::onLuaEngineCreate()
	{
		spdlog::info("AppFrame LuaEngine Listener Callback:onLuaEngineCreate.");
	}

	void AppFrame::onLuaEngineDestroy()
	{
		spdlog::info("AppFrame LuaEngine Listener Callback:onLuaEngineDestroy.");
		m_App->onLuaEngineDestroy();
	}
}