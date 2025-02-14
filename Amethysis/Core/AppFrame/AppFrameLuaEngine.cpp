// AppFrame类的LuaEngine部分实现
// Created by Loturias on 25-2-13.
//

#include "AppFrame.hpp"

namespace Amethysis::Core::App {
	void AppFrame::onLuaEngineCreate()
	{
		m_App->onLuaEngineCreate();
	}

	void AppFrame::onLuaEngineDestroy()
	{
		m_App->onLuaEngineDestroy();
	}
}