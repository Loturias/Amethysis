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
		void onUpdate();
		void onDestroy();

	private:
		HINSTANCE m_hInstance = nullptr;
		HWND m_hWnd = nullptr;

		Application* m_App = nullptr;
		Utility::FrameRate::FrameRateController m_FrameRateController{};

	public:
		// IWindow
		void onWindowCreate() override;
		void onWindowUpdate() override;
		void onWindowDestroy() override;

		// ILuaEngine

		void onLuaEngineCreate() override;
		void onLuaEngineDestroy() override;
	};
}
