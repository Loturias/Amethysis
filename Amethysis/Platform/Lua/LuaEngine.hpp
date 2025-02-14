// Lua脚本引擎类
// Created by Loturias on 25-2-13.
//

#pragma once
#include "../../SharedHeaders.hpp"
#include "lua.hpp"

namespace Amethysis::Platform::Lua
{
	///@class ILuaEngineListener
	struct ILuaEngineListener
	{
		virtual ~ILuaEngineListener() = default;

		virtual void onLuaEngineCreate() = 0;
		virtual void onLuaEngineDestroy() = 0;
	};

	///@class ILuaEngine
	///@brief Lua脚本引擎接口
	struct ILuaEngine
	{
	private:
		///@brief Lua虚拟机指针
		lua_State* m_LuaState = nullptr;

	public:
		ILuaEngine() = default;
		virtual ~ILuaEngine() = default;
		virtual void onLuaEngineCreate() = 0;
		virtual void onLuaEngineDestroy() = 0;

		[[nodiscard]] lua_State* getLuaState() const { return m_LuaState; }
		void setLuaState(lua_State* luaState) { m_LuaState = luaState; }
	};
}
