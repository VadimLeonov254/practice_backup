cmake_minimum_required(VERSION 3.10)

project(car_dynamic)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp car.cpp car.h)
