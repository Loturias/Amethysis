#include <Windows.h>

namespace LouRenderer
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