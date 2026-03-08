cmake_minimum_required(VERSION 3.10)

project(fcs)

set(CMAKE_CXX_STANDARD 17)

include_directories(headers)

set(SOURCE
    src/AirTrafficControl.cpp
    src/Pilot.cpp
    src/Plane.cpp
    src/main.cpp)

add_executable(main ${SOURCE})
