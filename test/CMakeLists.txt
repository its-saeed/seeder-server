cmake_minimum_required(VERSION 3.10)

find_package(Catch2 3 REQUIRED)

add_executable(tests "ClientManagerFunctionality.cpp" 
		ArgumentParserFunctionality.cpp)
target_link_libraries(tests PRIVATE libseeder Catch2::Catch2WithMain)

