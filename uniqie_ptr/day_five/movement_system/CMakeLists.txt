cmake_minimum_required(VERSION 3.10)

project(movement_system)

set(CMAKE_CXX_STANDARD 17)

include_directories(headers)

set(SOURCES
    src/entity.cpp
    src/mover.cpp
    src/main.cpp)

add_executable(main ${SOURCES})
