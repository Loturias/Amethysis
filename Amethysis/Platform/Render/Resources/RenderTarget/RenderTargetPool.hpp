// RenderTarget资源池
// Created by Loturias on 25-3-29.
#pragma once
#include "RenderTarget.hpp"
#include "../ResourcePool.hpp"
namespace Amethysis::Platform::Render
{
	enum class RenderTargetType
	{
		RT2D,
		RT3D
	};

	template<RenderTargetType RTType>
	class RenderTargetPool final : public GResourcePool<RenderTarget>
	{
		void Initialize() override;
		void Shutdown() override;

		RenderTarget* Create(const std::string& name) override;
		RenderTarget* Get(const std::string& name) override;
		bool Destroy(const std::string& name) override;
	};

	using RenderTarget2DPool = RenderTargetPool<RenderTargetType::RT2D>;
	using RenderTarget3DPool = RenderTargetPool<RenderTargetType::RT3D>;
}