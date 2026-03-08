cmake_minimum_required(VERSION 3.10)

project(racing_team)

set(CMAKE_CXX_STANDARD 17)

include_directories(headers)

set(SOURCES
    src/Car.cpp
    src/Driver.cpp
    src/Garage.cpp
    src/Race.cpp
    src/main.cpp)

add_executable(main ${SOURCES})
