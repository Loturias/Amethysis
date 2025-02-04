// 窗口接口
// Created by Loturias on 25-2-4.

#pragma once
#include "../../SharedHeaders.hpp"

namespace Amethysis::Platform::Windows
{
	///@brief Window事件监听器
	///@note 由AppFrame实现
	struct IWindowEventListener
	{
		virtual ~IWindowEventListener() = default;
		virtual void onWindowCreate() = 0;
		virtual void onWindowUpdate() = 0;
		virtual void onWindowDestroy() = 0;
	};

	enum class WindowStatus
	{
		NOT_INITIALIZED,
		CREATED,
		UPDATED,
		DESTROYED
	};

	///@brief 窗口接口
	struct IWindow
    {
	private:
		WindowStatus m_Status = WindowStatus::NOT_INITIALIZED;
		HINSTANCE m_hInstance = nullptr;
		HWND m_hWnd = nullptr;
		std::shared_ptr<IWindowEventListener> m_WindowListener = nullptr;

		long m_Width = 0;
		long m_Height = 0;
	public:
		virtual ~IWindow() = default;
		virtual void onWindowCreate(HINSTANCE hInstance) = 0;
		virtual void onWindowUpdate() = 0;
		virtual void onWindowDestroy() = 0;

        virtual void onWindowResize(int width, int height) = 0;
        virtual void onWindowMove(int x, int y) = 0;
        virtual void onWindowFocus() = 0;
        virtual void onWindowLostFocus() = 0;

        virtual UINT getFrameRate() = 0;

		int getWidth() const { return m_Width; }
		int getHeight() const { return m_Height; }
		void setWidth(const long width) { m_Width = width; }
		void setHeight(const long height) { m_Height = height; }

		void setStatus(const WindowStatus status) { m_Status = status; }
    	[[nodiscard]] WindowStatus getStatus() const { return m_Status; }

		void setHInstance(const HINSTANCE hInstance) { m_hInstance = hInstance; }
		[[nodiscard]] HINSTANCE getHInstance() const { return m_hInstance; }

		void setHWnd(const HWND hWnd) { m_hWnd = hWnd; }
		[[nodiscard]] HWND getHWnd() const { return m_hWnd; }

		void setListener(IWindowEventListener* listener) { m_WindowListener.reset(listener); }
		[[nodiscard]] std::shared_ptr<IWindowEventListener> getListener() const { return m_WindowListener; }
	};
}
