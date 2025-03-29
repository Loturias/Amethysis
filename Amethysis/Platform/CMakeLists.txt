set(AMETHYSIS_SRC ${AMETHYSIS_SRC}
	${CMAKE_CURRENT_SOURCE_DIR}/Window/window.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/Window/window.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/Lua/LuaEngine.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/Lua/LuaEngine.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/Thread/ThreadPool.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/Thread/ThreadPool.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/Render/RenderCore/RenderCycle/RenderCycle.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/Render/RenderCore/RenderGraph/RenderGraph.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/Render/RenderCore/RenderPass/RenderPass.hpp

	${CMAKE_CURRENT_SOURCE_DIR}/Render/Resources/ResourcePool.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/Render/Resources/RenderTarget/RenderTarget.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/Render/Resources/RenderTarget/RenderTargetPool.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/Render/Resources/RenderTarget/RenderTargetPool.cpp

	PARENT_SCOPE # 这个关键字将变量的修改传递回父作用域
)

# 加载静态库
target_link_libraries(${PROJECT_NAME} PRIVATE d3d12.lib dxgi.lib D3DCompiler.lib)