cmake_minimum_required(VERSION 3.10)

project(resource_mamanger)

set(CMAKE_CXX_STANDARD 17)

include_directories(headers)

set(SOURCES
    src/FileManager.cpp
    src/File.cpp
    src/main.cpp)

add_executable(main ${SOURCES})
