# 该文件来源于LuaSTG-Sub
# 原项目地址：https://github.com/Legacy-LuaSTG-Engine/LuaSTG-Sub
function(luastg_target_common_options __TARGET__)
    target_compile_options(${__TARGET__} PRIVATE
            "/MP" # 多核编译
            "/utf-8" # 源字符集：UTF-8
            "$<$<CONFIG:Debug>:/Zi>" # 调试信息
    )
    target_link_options(${__TARGET__} PRIVATE
            # "/DEPENDENTLOADFLAG:0x800" # Windows 10 1607+ 强制 DLL 搜索目录为系统目录
    )
    if(CMAKE_SIZEOF_VOID_P EQUAL 4) # 如果是32位
        target_compile_options(${__TARGET__} PRIVATE
                "/arch:SSE2" # 支持编译到SSE2指令集
        )
        target_link_options(${__TARGET__} PRIVATE
                "$<$<CONFIG:Debug>:/SAFESEH:NO>"
        )
    endif()
    set_target_properties(${__TARGET__} PROPERTIES
            C_STANDARD 17
            C_STANDARD_REQUIRED ON
            CXX_STANDARD 17
            CXX_STANDARD_REQUIRED ON
    )
    target_compile_definitions(${__TARGET__} PRIVATE
            _UNICODE
            UNICODE
    )
endfunction()

function(luastg_target_common_options2 __TARGET__)
    target_compile_options(${__TARGET__} PRIVATE
            "/MP"
            "/utf-8"
            "$<$<CONFIG:Debug>:/Zi>"
    )
    target_link_options(${__TARGET__} PRIVATE
            # "/DEPENDENTLOADFLAG:0x800" # Windows 10 1607+ 强制 DLL 搜索目录为系统目录
    )
    if(CMAKE_SIZEOF_VOID_P EQUAL 4)
        target_compile_options(${__TARGET__} PRIVATE
                "/arch:SSE2"
        )
        target_link_options(${__TARGET__} PRIVATE
                "$<$<CONFIG:Debug>:/SAFESEH:NO>"
        )
    endif()
    set_target_properties(${__TARGET__} PROPERTIES
            C_STANDARD 17
            C_STANDARD_REQUIRED ON
            CXX_STANDARD 20
            CXX_STANDARD_REQUIRED ON
    )
endfunction()

function(luastg_target_more_warning __TARGET__)
    target_compile_options(${__TARGET__} PRIVATE
            "/W4" # 启用更高的警告级别
    )
endfunction()
