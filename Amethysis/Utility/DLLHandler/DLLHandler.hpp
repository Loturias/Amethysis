#pragma once
#include <Windows.h>

namespace Amethysis::Utility
{
	class DLLHandler
	{
	public:
		DLLHandler(const char* path);
		~DLLHandler();

		/// Get the handle to the loaded DLL
		HMODULE GetModule() const { return m_module; }

	private:
		HMODULE m_module; /// Handle to the loaded DLL
	};
}