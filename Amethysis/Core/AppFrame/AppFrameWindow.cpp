// AppFrame类的Window部分实现
// Created by Loturias on 25-2-4.

#include "AppFrame.hpp"

namespace Amethysis::Core::App {
	void AppFrame::onWindowCreate()
	{
		spdlog::info("Creating desktop window...");

		m_App->onWindowCreate(m_hInstance);
		m_hWnd = m_App->getHWnd();

		if (m_hWnd == nullptr)
		{
			spdlog::error("Failed to create desktop window.");
			throw std::runtime_error("Failed to create desktop window.");
		}
	}

	void AppFrame::onWindowUpdate()
	{
		m_App->onWindowUpdate();
	}

	void AppFrame::onWindowDestroy()
	{
		m_App->onWindowDestroy();
	}
}
