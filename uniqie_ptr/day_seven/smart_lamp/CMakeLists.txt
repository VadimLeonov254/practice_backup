cmake_minimum_required(VERSION 3.10)

project(smart_lamp)

set(CMAKE_CXX_STANDARD)

include_directories(headers)

set(SOURCES
    src/LampState.cpp
    src/OffState.cpp
    src/OnState.cpp
    src/SmartLamp.cpp
    src/main.cpp)

add_executable(main ${SOURCES})
