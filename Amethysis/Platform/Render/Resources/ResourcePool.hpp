// 资源池核心类
// Created by Loturias on 25-3-18.
#pragma once
#include "../../../SharedHeaders.hpp"

namespace Amethysis::Platform::Render
{
	template<typename ObjectType>
	class GResourcePool
	{
	private:
		std::unordered_map<std::string, ObjectType*> m_Resources;
	public:
		GResourcePool() = default;
		virtual ~GResourcePool() = default;

		virtual void Initialize() = 0;
		virtual void Shutdown() = 0;

		virtual ObjectType* Create(const std::string& name) = 0;
		virtual ObjectType* Get(const std::string& name) = 0;
		virtual bool Destroy(const std::string& name) = 0;

	};
}