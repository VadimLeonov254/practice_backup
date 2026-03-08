cmake_minimum_required(VERSION 3.10)

project(workshop)

set(CMAKE_CXX_STANDARD)

include_directories(headers)

set(SOURCE
    src/Tool.cpp
    src/Worker.cpp
    src/Workshop.cpp
    src/main.cpp)

add_executable(main ${SOURCE})
