add_library(libseeder argument-parser/ArgumentParser.cpp)

target_include_directories(libseeder PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
		PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/argument-parser)
