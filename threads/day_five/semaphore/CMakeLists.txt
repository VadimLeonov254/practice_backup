cmake_minimum_required(VERSION 3.10)

project(semaphore)

set(CMAKE_CXX_STANDARD 17)

include_directories(headers)

set(SOURCE 
    src/Semaphore.cpp
    src/main.cpp)

add_executable(main ${SOURCE})
