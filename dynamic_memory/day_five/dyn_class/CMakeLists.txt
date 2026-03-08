cmake_minimum_required(VERSION 3.10)

project(dyn_class)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp dyn_class.h dyn_class.cpp)
