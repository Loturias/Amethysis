// RenderTarget池 方法实现
// Created by Loturias on 25-3-29.

#include "RenderTargetPool.hpp"

namespace Amethysis::Platform::Render {
	void RenderTargetPool::Initialize()
	{

	}

	void RenderTargetPool::Shutdown()
	{

	}

	auto RenderTargetPool::Create(const std::string& name) -> RenderTarget*
	{
		return nullptr;
	}

	auto RenderTargetPool::Get(const std::string& name) -> RenderTarget*
	{
		return nullptr;
	}

	auto RenderTargetPool::Destroy(const std::string& name) -> bool
	{
		return false;
	}

}
