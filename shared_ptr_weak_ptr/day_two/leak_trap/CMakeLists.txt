cmake_minimum_required(VERSION 3.10)

project(leak_trap)

set(CMAKE_CXX_STANDARD 17)

add_executable(main leak_trap.cpp)
