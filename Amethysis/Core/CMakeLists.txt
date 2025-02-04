set(AMETHYSIS_SRC ${AMETHYSIS_SRC}
        ${CMAKE_CURRENT_SOURCE_DIR}/AppFrame/AppFrame.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/AppFrame/AppFrame.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/AppFrame/AppFrameWindow.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/Application/Application.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Application/ApplicationIWindow.cpp

        PARENT_SCOPE # 这个关键字将变量的修改传递回父作用域
)