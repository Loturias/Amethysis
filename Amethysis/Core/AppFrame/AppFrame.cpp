// AppFrame类实现
// Created by Loturias on 25-2-4.

#include "AppFrame.hpp"

namespace Amethysis::Core::App {
	AppFrame::AppFrame(const HINSTANCE hInstance)
		:m_hInstance(hInstance)
	{
		// 对接Application
		m_App = &Application::getInstance();
		m_App->setListener(dynamic_cast<IWindowEventListener*>(this));

		// 加载DLL
		m_DLLHandles.emplace_back("lua54.dll");

		onCreate();

		spdlog::info("App Framework initialize succeed.");
		spdlog::info("Framework Loop Start.");

		while (m_App->IsRunning())
		{
			onUpdate();
		}

		onDestroy();
	}

	void AppFrame::onCreate()
	{
		spdlog::info("Creating Application Framework...");
		// 初始化帧率控制器
		m_FrameRateController.Init(60);

		onWindowCreate();

		onLuaEngineCreate();

		m_App->isRunning = true;
	}

	void AppFrame::onUpdate()
	{
		m_FrameRateController.frameStart();
		m_App->FrameCounter++;

		onWindowUpdate();

		m_FrameRateController.frameEnd();
	}

	void AppFrame::onDestroy()
	{
		spdlog::info("Start destroying App Framework...");

		onWindowDestroy();

		onLuaEngineDestroy();

		spdlog::info("App framework destroyed.");
	}

}

