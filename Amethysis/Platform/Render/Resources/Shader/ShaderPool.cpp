// Shader池实现
// Created by Loturias on 25-3-29.

#include "ShaderPool.hpp"

namespace Amethysis::Platform::Render {
	template <ShaderType SType>
	void ShaderPool<SType>::Initialize()
	{

	}

	template <ShaderType SType>
	void ShaderPool<SType>::Shutdown()
	{

	}

	template <ShaderType SType>
	auto ShaderPool<SType>::Create(const std::string& name) -> Shader*
	{
		return nullptr;
	}

	template <ShaderType SType>
	auto ShaderPool<SType>::Get(const std::string& name) -> Shader*
	{
		return nullptr;
	}

	template <ShaderType SType>
	auto ShaderPool<SType>::Destroy(const std::string& name) -> bool
	{
		return false;
	}

}