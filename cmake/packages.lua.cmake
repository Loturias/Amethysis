add_library(lua54 SHARED IMPORTED)

target_include_directories(lua54 INTERFACE
	${CMAKE_SOURCE_DIR}/dependencies/lua/Inc
)

set_target_properties(lua54 PROPERTIES
	LINKER_LANGUAGE CXX
	IMPORTED_IMPLIB "${CMAKE_SOURCE_DIR}/dependencies/lua/lua54.lib" # 导入库
	IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/dependencies/lua/lua54.dll" # 导入dll
)