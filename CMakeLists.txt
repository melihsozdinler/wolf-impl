cmake_minimum_required(VERSION 3.19)
project(wolf)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)
add_executable(wolf main.cpp)
target_link_libraries(wolf wolflib)