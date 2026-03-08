cmake_minimum_required(VERSION 3.10)

project(person)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp person.h person.cpp)
