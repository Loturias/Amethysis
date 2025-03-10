// AppFrame类的Window部分实现
// Created by Loturias on 25-2-4.

#include "AppFrame.hpp"

namespace Amethysis::Core::App {
	void AppFrame::onWindowCreate()
	{
		spdlog::info("AppFrame Window Listener Callback:onWindowCreate.");
	}

	void AppFrame::onWindowUpdate()
	{
		spdlog::info("AppFrame Window Listener Callback:onWindowUpdate.");
	}

	void AppFrame::onWindowDestroy()
	{
		spdlog::info("AppFrame Window Listener Callback:onWindowDestroy.");
		m_MainLoopCV.notify_one(); // 唤起主线程
	}
}
