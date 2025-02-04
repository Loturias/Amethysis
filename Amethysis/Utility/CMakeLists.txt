set(AMETHYSIS_SRC ${AMETHYSIS_SRC}
    ${CMAKE_CURRENT_SOURCE_DIR}/Console/Console.hpp

    ${CMAKE_CURRENT_SOURCE_DIR}/DLLHandler/DLLHandler.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/DLLHandler/DLLHandler.cpp

    PARENT_SCOPE # 这个关键字将变量的修改传递回父作用域
)