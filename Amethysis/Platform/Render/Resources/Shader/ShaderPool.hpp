// Shader对象池
// Created by Loturias on 25-3-29.
#pragma once
#include "../ResourcePool.hpp"
#include "Shader.hpp"
#include "ShaderPool.hpp"

namespace Amethysis::Platform::Render
{
	enum class ShaderType
	{
		Vertex,
		Pixel,
	};

	template <ShaderType SType>
	class ShaderPool final : public GResourcePool<Shader>
	{
		void Initialize() override;
		void Shutdown() override;

		Shader* Create(const std::string& name) override;
		Shader* Get(const std::string& name) override;
		bool Destroy(const std::string& name) override;
	};

	using VertexShaderPool = ShaderPool<ShaderType::Vertex>;
	using PixelShaderPool = ShaderPool<ShaderType::Pixel>;
}
