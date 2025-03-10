// AppFrame 框架类
// Created by Loturias on 25-2-4.
//

#pragma once
#include "../Application/Application.hpp"
#include "../../Utility/Console/Console.hpp"
#include "../../Utility/FrameRateController/FrameRateController.hpp"
#include "../../Utility/DLLHandler/DLLHandler.hpp"

using Application = Amethysis::Core::App::Application;

namespace Amethysis::Core::App
{
	struct AppFrame final
		: Platform::Windows::IWindowEventListener
		, Platform::Lua::ILuaEngineListener
	{
		explicit AppFrame(HINSTANCE hInstance);
		~AppFrame() override = default;
		AppFrame(const AppFrame&) = delete;
		AppFrame& operator=(const AppFrame&) = delete;

		std::vector<Utility::DLLHandler> m_DLLHandles{}; // DLL句柄

		void onCreate();

		// 程序主循环控制

		///@brief 用于挂起启动线程的互斥锁
		std::mutex m_MainLoopMutex{};
		///@brief 用于挂起启动线程的条件变量
		std::condition_variable m_MainLoopCV{};

		/// @brief 向线程池发射主循环任务
		void DispatchMainLoop();

		void LogicLoop();
		void RenderLoop();

		void onLogicUpdate();
		void onRenderUpdate();

		void onUpdate();
		void onDestroy();

	private:
		HINSTANCE m_hInstance = nullptr;
		HWND m_hWnd = nullptr;

		Application* m_App = nullptr;
		Utility::FrameRate::FrameSyncer m_FrameSyncer{};
		// Utility::FrameRate::FrameRateController m_FrameRateController{};

	public:
		// Listener Callback

		// IWindow

		void onWindowCreate() override;
		void onWindowUpdate() override;
		void onWindowDestroy() override;

		// ILuaEngine

		void onLuaEngineCreate() override;
		void onLuaEngineDestroy() override;
	};
}
