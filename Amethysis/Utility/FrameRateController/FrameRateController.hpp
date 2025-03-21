#pragma once
// #pragma comment(lib, "winmm.lib")
#include <profileapi.h>

using TIMESTAMP = unsigned long long;

namespace Amethysis::Utility::FrameRate
{
	class FrameSyncer
	{
	public:
		FrameSyncer();
		FrameSyncer(int TargetFrameRate, int TargetRenderRate);
		~FrameSyncer() = default;

		LARGE_INTEGER m_Frequency{};

		///@brief 程序启动时记录的时间戳
		TIMESTAMP m_StartTimeStamp{};
		///@brief 上一逻辑帧记录的时间戳
		TIMESTAMP m_LastFrameTime{};
		///@brief 上一渲染帧记录的时间戳
		TIMESTAMP m_LastRenderTime{};

		///@brief 逻辑帧累计时间
		double m_FrameAccumulatedTime = 0.0;
		///@brief 渲染帧累计时间
		double m_RenderAccumulatedTime = 0.0;

		int m_TargetFrameRate = 60;
		int m_TargetRenderRate = 120;

		static FrameSyncer& getInstance()
		{
			static FrameSyncer instance;
			return instance;
		}

		FrameSyncer(const FrameSyncer&) = delete;
		FrameSyncer& operator=(const FrameSyncer&) = delete;

		static void Init();

		///@brief 设置目标帧率
		void SetFrameRate(int TargetFrameRate, int TargetRenderRate);

		///@brief 获取当前时间戳
		static TIMESTAMP GetCurrentTimeStamp();

		///@brief 获取两个时间戳的时间差
		///@return 返回两帧之间的时间差，单位由设备的查询精度决定
		static double GetTimeLag(TIMESTAMP TimeStamp1, TIMESTAMP TimeStamp2);

		static long long GetFrequency();
	};
}