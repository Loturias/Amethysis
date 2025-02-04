// 应用程序框架实现
// Created by Loturias on 25-2-4.

#pragma once
#include "../../SharedHeaders.hpp"
#include "../../Platform/Window/window.hpp"

namespace Amethysis::Core::App {
	struct Application final
		: Platform::Windows::IWindow
	{
		///@brief 获取全局静态实例
		static Application& getInstance()
		{
			static Application instance;
			return instance;
		}

		// 禁止拷贝构造和赋值

		Application(const Application&) = delete;
		Application& operator=(const Application&) = delete;

		///@brief 帧计数器
		ULONG FrameCounter = 0;

		/// IWindow接口
		void onWindowCreate(HINSTANCE hInstance) override;
		void onWindowUpdate() override;
		void onWindowDestroy() override;
		void onWindowResize(int width, int height) override;
		void onWindowMove(int x, int y) override;
		void onWindowFocus() override;
		void onWindowLostFocus() override;
		UINT getFrameRate() override;
	private:
		///@brief 构造函数，禁止外部实例化，仅允许单例模式
		Application() = default;
		~Application() override = default;
	};
}
