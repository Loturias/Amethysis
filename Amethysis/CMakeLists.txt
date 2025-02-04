add_executable(Amethysis WIN32)

# 设置编译选项
luastg_target_common_options(Amethysis)
luastg_target_more_warning(Amethysis)

set(AMETHYSIS_SRC
    Main.cpp
)

# 子模块目录列表

# 添加源文件到工程
# 根据目录结构将源文件分组
source_group(TREE ${CMAKE_CURRENT_LIST_DIR} FILES ${RENDERER_SOURCES})
# 添加源文件到工程
target_sources(Amethysis PRIVATE ${AMETHYSIS_SRC})

# 将其他库链接到exe
target_link_libraries(Amethysis PRIVATE
        spdlog
        DirectXTexMini
        lua54
)

# 拷贝Lua DLL
set(DLL_SOURCE ${CMAKE_SOURCE_DIR}/dependencies/lua/lua54.dll)
set(DLL_TARGET_DIR ${CMAKE_BINARY_DIR}/Amethysis/)

add_custom_target(CopyLuaDLL ALL
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${DLL_SOURCE} ${DLL_TARGET_DIR}
        COMMENT "拷贝动态库"
)

add_dependencies(Amethysis CopyLuaDLL) # 自动执行