#include "FrameRateController.hpp"

namespace Amethysis::Utility::FrameRate
{
	FrameSyncer::FrameSyncer()
	{
		m_TargetFrameRate = 60;
        m_TargetRenderRate = 120;
		m_StartTimeStamp = GetCurrentTimeStamp();
        m_LastFrameTime = GetCurrentTimeStamp();
		m_LastRenderTime = GetCurrentTimeStamp();
	}

	FrameSyncer::FrameSyncer(const int TargetFrameRate, const int TargetRenderRate)
	{
		m_TargetFrameRate = TargetFrameRate;
		m_TargetRenderRate = TargetRenderRate;
		m_LastFrameTime = 0;
	}

	void FrameSyncer::Init()
	{
		QueryPerformanceFrequency(&getInstance().m_Frequency);
		spdlog::info("Windows high precision timer performance frequency:" + std::to_string(getInstance().m_Frequency.QuadPart));
		LARGE_INTEGER timeStamp;
		QueryPerformanceCounter(&timeStamp);
		getInstance().m_StartTimeStamp = timeStamp.QuadPart;
	}

	void FrameSyncer::SetFrameRate(const int TargetFrameRate, const int TargetRenderRate)
	{
		m_TargetFrameRate = TargetFrameRate;
        m_TargetRenderRate = TargetRenderRate;
	}

	TIMESTAMP FrameSyncer::GetCurrentTimeStamp()
    {
		LARGE_INTEGER timeStamp;
		QueryPerformanceCounter(&timeStamp);
		return timeStamp.QuadPart;
    }

	double FrameSyncer::GetTimeLag(const TIMESTAMP TimeStamp1, const TIMESTAMP TimeStamp2)
    {
		return TimeStamp2 > TimeStamp1 ? TimeStamp2 - TimeStamp1 : TimeStamp1 - TimeStamp2;
    }

	long long FrameSyncer::GetFrequency()
	{
		return getInstance().m_Frequency.QuadPart;
	}
}
