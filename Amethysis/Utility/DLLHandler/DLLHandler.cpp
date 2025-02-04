#include "DLLHandler.hpp"

namespace LouRenderer
{
	DLLHandler::DLLHandler(const char* path)
	{
		m_module = LoadLibraryA(path);
		if (m_module == nullptr)
		{
			spdlog::error("Load DLL Failed. Error Code:{}", GetLastError());
			throw std::runtime_error("Load DLL Failed.");
		}
		else
		{
			spdlog::info("Load DLL Succeed.DLL info:{}",path);
		}
	}

	DLLHandler::~DLLHandler()
	{
		FreeLibrary(m_module);
	}
}