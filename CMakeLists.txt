cmake_minimum_required(VERSION 3.10)

project(seeder CXX)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(libseeder)
add_subdirectory(seeder)
add_subdirectory(test)
