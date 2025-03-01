#pragma once
#pragma comment(lib, "winmm.lib")
#include <timeapi.h>
#include <Windows.h>

namespace Amethysis::Utility::FrameRate
{
	/// @brief 简单的计时器，用于控制帧率
	class FrameRateController
	{
		bool Initialized = false;
		int m_FrameRate{};
		DWORD m_FrameTime{};
		DWORD m_StartTime{};
		DWORD m_CurrentFrameTime{};
		DWORD m_EndTime{};
		DWORD m_LastFrameTime{};
	public:
		FrameRateController();
		~FrameRateController();

		/// @brief 初始化，必须在使用前调用
		void Init();

		void Init(int TargetFPS);

		void setFrameRate(int frameRate);

		void frameStart();

		void frameEnd();

		std::wstring getAvgFPS() const;
	};
}