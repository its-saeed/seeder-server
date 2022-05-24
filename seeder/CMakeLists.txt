add_executable(seeder main.cpp)

target_link_libraries(seeder libseeder pthread evpp glog)
