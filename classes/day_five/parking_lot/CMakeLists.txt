cmake_minimum_required(VERSION 3.10)

project(parking_lot)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp parking_lot.cpp parking_lot.h)
