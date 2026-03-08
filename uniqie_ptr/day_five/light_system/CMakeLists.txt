cmake_minimum_required(VERSION 3.10)

project(light_system)

set(CMAKE_CXX_STANDARD)

include_directories(headers)

set(SOURCES
    src/DimState.cpp
    src/OffState.cpp
    src/OnState.cpp
    src/SmartLight.cpp
    src/main.cpp
    )

add_executable(main ${SOURCES})
