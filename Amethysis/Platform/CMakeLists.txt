set(AMETHYSIS_SRC ${AMETHYSIS_SRC}
	${CMAKE_CURRENT_SOURCE_DIR}/Window/window.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/Window/window.cpp

	PARENT_SCOPE # 这个关键字将变量的修改传递回父作用域
)

# 加载静态库
target_link_libraries(${PROJECT_NAME} PRIVATE d3d12.lib dxgi.lib D3DCompiler.lib)