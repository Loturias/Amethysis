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

		DispatchMainLoop(); // 启动主循环

		{
			// 启动执行线程后，主线程挂起，等待执行线程线程唤起
			std::unique_lock<std::mutex> lock(m_MainLoopMutex);
			m_MainLoopCV.wait(lock, [this] { return !m_App->IsRunning(); });
		}

		// 旧的帧同步的主循环方案
		/*while (m_App->IsRunning())
		{
			onUpdate();
		}*/

		onDestroy();
	}

	void AppFrame::onCreate()
	{
		spdlog::info("Creating Application Framework...");

		m_App->thread_pool.OnInit(4);

		m_FrameSyncer.Init();
		// 初始化帧率控制器
		// m_FrameRateController.Init(60);

		const auto LuaRes = m_App->thread_pool.SubmitTask(&Application::onLuaEngineCreate, m_App);
		LuaRes.wait();

		m_App->isRunning = true;
	}

	void AppFrame::DispatchMainLoop()
	{
		m_App->thread_pool.SubmitTask(&AppFrame::LogicLoop, this);
		// m_App->thread_pool.SubmitTask(&AppFrame::RenderLoop, this);
	}

	void AppFrame::LogicLoop()
	{
		// 注意：Windows要求窗口创建和消息循环在同一线程执行
		// 因此将创建窗口的代码迁移到LogicLoop中
		// 这是一个特例！！特例！！
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

		spdlog::info("Logic thread started.Thread ID:{}", 114514);
		while (m_App->IsRunning())
		{
			static auto& syncer_ins =  Utility::FrameRate::FrameSyncer::getInstance();

			int MaxRetryCount = 3;
			int RetryCount = 0;

			// 基于时间戳的计时系统
			// 使用了Windows平台提供的高精度计时器，在本台设备上频率为10^7。

			const double time_step = 1.0 / syncer_ins.m_TargetFrameRate * syncer_ins.GetFrequency();
			const auto lastFrameTime = syncer_ins.m_LastFrameTime;
			const auto currentTime = syncer_ins.GetCurrentTimeStamp();
			const auto timeLag = syncer_ins.GetTimeLag(lastFrameTime, currentTime);
			syncer_ins.m_FrameAccumulatedTime += timeLag;
			syncer_ins.m_LastFrameTime = currentTime;

			while (syncer_ins.m_FrameAccumulatedTime >= time_step && RetryCount < MaxRetryCount)
			{
				RetryCount++;
				syncer_ins.m_FrameAccumulatedTime -= time_step;
				onLogicUpdate();
			}
		}
	}

	void AppFrame::RenderLoop()
	{
		// 暂时什么都不做
	}

	void AppFrame::onLogicUpdate()
	{
		m_App->FrameCounter++;
		m_App->onWindowUpdate();
	}

	void AppFrame::onRenderUpdate()
	{

	}

	void AppFrame::onUpdate()
	{

	}

	void AppFrame::onDestroy()
	{
		spdlog::info("Start destroying App Framework...");

		m_App->onWindowDestroy();
		m_App->onLuaEngineDestroy();
		m_App->thread_pool.OnDestroy();

		spdlog::info("App framework destroyed.");
	}

}

