cmake_minimum_required(VERSION 3.30)
project(Amethysis)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置全局属性，使得生成的项目文件夹结构更加清晰
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# 导入通用编译选项
include(cmake/TargetCommonOptions.cmake)

# 使用静态运行时库
include(cmake/msvc.crt.cmake)
msvc_static_runtime_library()

# 导入CPM库
include(cmake/cpm/loader.cpm.cmake)
CPMInitialize()

# 第三方库
include(cmake/packages.devtool.cmake) # spdlog
include(cmake/packages.directx.cmake) # DirectX开发工具：DXTex
include(cmake/packages.lua.cmake) # Lua 5.4

# 项目源码
add_subdirectory(Amethysis)
