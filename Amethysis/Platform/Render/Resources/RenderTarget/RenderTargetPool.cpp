// RenderTarget池 方法实现
// Created by Loturias on 25-3-29.

#include "RenderTargetPool.hpp"

namespace Amethysis::Platform::Render {
	template<RenderTargetType RTType>
	void RenderTargetPool<RTType>::Initialize() {
	}

	template<RenderTargetType RTType>
	void RenderTargetPool<RTType>::Shutdown() {
	}

	template<RenderTargetType RTType>
	RenderTarget* RenderTargetPool<RTType>::Create(const std::string& name) {
		return nullptr;
	}

	template<RenderTargetType RTType>
	RenderTarget* RenderTargetPool<RTType>::Get(const std::string& name) {
		return nullptr;
	}

	template<RenderTargetType RTType>
	bool RenderTargetPool<RTType>::Destroy(const std::string& name) {
		return false;
	}

}
