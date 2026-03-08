cmake_minimum_required(VERSION 3.10)

project(vehicle_simulator)

set(CMAKE_CXX_STANDARD 17)

include_directories(headers)

set(SOURCES
    source/main.cpp
    source/Car.cpp
    source/Bike.cpp
    source/Garage.cpp
    source/Factory.cpp
)

add_executable(main ${SOURCES})
