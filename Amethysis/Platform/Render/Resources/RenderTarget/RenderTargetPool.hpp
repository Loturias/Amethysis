// RenderTarget资源池
// Created by Loturias on 25-3-29.
#pragma once
#include "RenderTarget.hpp"
#include "../ResourcePool.hpp"
namespace Amethysis::Platform::Render
{
	class RenderTargetPool final : public GResourcePool<RenderTarget>
	{
		void Initialize() override;
		void Shutdown() override;

		RenderTarget* Create(const std::string& name) override;
		RenderTarget* Get(const std::string& name) override;
		bool Destroy(const std::string& name) override;
	};
}