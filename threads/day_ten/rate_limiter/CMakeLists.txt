cmake_minimum_required(VERSION 3.10)

project(rate_limiter)

set(CMAKE_CXX_STANDARD 17)

add_executable(main rate_limiter.cpp main.cpp)
