#include "FrameRateController.hpp"

namespace Amethysis::Utility::FrameRate
{
	FrameRateController::FrameRateController()
	{
		m_FrameRate = 0;
		m_FrameTime = 0;

		m_StartTime = 0;
		m_CurrentFrameTime = 0;
		m_EndTime = 0;
		m_LastFrameTime = 0;
	}

	FrameRateController::~FrameRateController()
	{
		if (Initialized)
		{
			timeEndPeriod(1);
			return;
		}
		// 未初始化就销毁对象时，输出错误信息
		spdlog::error("Frame Rate Controller is not initialized!");
	}

	void FrameRateController::Init()
	{
		timeBeginPeriod(1);
		m_FrameRate = 60;
		m_FrameTime = static_cast<DWORD>(1.0f / 60 * 1000);
		Initialized = true;
		spdlog::info("Frame Rate Controller initialized.Target FPS:"+std::to_string(m_FrameRate));
		spdlog::info("Frame Time:" + std::to_string(m_FrameTime));
	}

	void FrameRateController::Init(int TargetFPS)
	{
		timeBeginPeriod(1);
		m_FrameRate = TargetFPS;
		m_FrameTime = static_cast<DWORD>(1.0f / TargetFPS * 1000);
		Initialized = true;
		spdlog::info("Frame Rate Controller initialized.Target FPS:" + std::to_string(m_FrameRate));
		spdlog::info("Frame Time:" + std::to_string(m_FrameTime) + "ms");
	}

	void FrameRateController::setFrameRate(int TargetFPS)
	{
		m_FrameRate = TargetFPS;
		m_FrameTime = static_cast<DWORD>(1.0f / TargetFPS * 1000);
	}

	void FrameRateController::frameStart()
	{
		if (!Initialized)
		{
			spdlog::error("Frame Rate Controller is not initialized!");
			return;
		}
		m_StartTime = timeGetTime(); // 刷新帧起始时间，由WindowsAPI提供
	}

	void FrameRateController::frameEnd()
	{
		m_EndTime = timeGetTime();

		m_CurrentFrameTime = m_EndTime - m_StartTime;
		if (m_CurrentFrameTime < m_FrameTime)
		{
			// 如果这一帧的时间小于目标帧时间，就等待
			// spdlog::info("Sleeping for " + std::to_string((m_FrameTime - m_CurrentFrameTime) * 1000) + "ms");
			Sleep(m_FrameTime - m_CurrentFrameTime);
		}
		m_LastFrameTime = timeGetTime() - m_StartTime; // 计算这一帧的时间，重新取一个时间戳用于计算
	}

	std::wstring FrameRateController::getAvgFPS() const
	{
		std::wstring fps = L"FPS: ";
		float t = 1000.0f / m_LastFrameTime;

		fps += std::to_wstring(t);
		return fps;
	}
}