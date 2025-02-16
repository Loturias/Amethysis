// Application的IWindow的接口实现
// Created by Loturias on 25-2-4.

#include "Application.hpp"

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
		break;
	case WM_DESTROY:
		Amethysis::Core::App::Application::getInstance().isRunning = false;
		PostQuitMessage(0);
		break;
	case WM_SIZE: // NOLINT(*-branch-clone)
		Amethysis::Core::App::Application::getInstance().onWindowResize(LOWORD(lParam), HIWORD(lParam));
		break;
	case WM_MOVE:
		Amethysis::Core::App::Application::getInstance().onWindowMove(LOWORD(lParam), HIWORD(lParam));
		break;
	case WM_SETFOCUS:
		Amethysis::Core::App::Application::getInstance().onWindowFocus();
		break;
	case WM_KILLFOCUS:
		Amethysis::Core::App::Application::getInstance().onWindowLostFocus();
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

namespace Amethysis::Core::App {
	void Application::onWindowCreate(const HINSTANCE hInstance)
	{
		WNDCLASS wc{};
		wc.lpfnWndProc = WndProc;
		wc.hInstance = GetModuleHandle(nullptr);
		wc.lpszClassName = L"Amethysis";

		RegisterClass(&wc);

		const HWND hWnd = CreateWindowEx(
			0,
			wc.lpszClassName,
			wc.lpszClassName,
			WS_OVERLAPPEDWINDOW, // 普通的带标题栏和边框的窗口
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			1920,
			1080,
			nullptr,
			nullptr,
			wc.hInstance,
			nullptr
		);
		// 显示窗口
		ShowWindow(hWnd,SW_SHOW);

		setHInstance(hInstance);
		setHWnd(hWnd);
		setWidth(1920);
		setHeight(1080);

		setStatus(Platform::Windows::WindowStatus::CREATED);
		this->isRunning = true;
	}

	void Application::onWindowUpdate()
	{
		MSG msg{};
		while (PeekMessage(&msg, getHWnd(), 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	void Application::onWindowDestroy()
	{
		DestroyWindow(getHWnd());
		setStatus(Platform::Windows::WindowStatus::DESTROYED);
		spdlog::info("Window Destroyed.");
	}

	void Application::onWindowResize(const int width, const int height)
	{
		//@TODO 接入窗口大小调整事件
		spdlog::info(L"Window Resize occurred.");
	}

	void Application::onWindowMove(const int x, const int y)
	{
		//@TODO 接入窗口移动事件
		spdlog::info(L"Window Move occurred.");
	}

	void Application::onWindowFocus()
	{
		//@TODO 接入窗口获得焦点事件
		spdlog::info(L"Window Focus occurred.");
	}

	void Application::onWindowLostFocus()
	{
		//@TODO 接入窗口失去焦点事件
		spdlog::info(L"Window Lost Focus occurred.");
	}

	UINT Application::getFrameRate()
	{
		//@todo: 接入帧率控制组件
		return 1;
	}
}
