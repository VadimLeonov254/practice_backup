cmake_minimum_required(VERSION 3.10)

project(library_simulation)

set(CMAKE_CXX_STANDARD 17)

include_directories(headers)

set(SOURCES
    src/main.cpp
    src/factory.cpp
    src/fiction.cpp
    src/library.cpp
    src/nonfiction.cpp
    src/shelf.cpp)

add_executable(main ${SOURCES})
