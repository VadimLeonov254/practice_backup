cmake_minimum_required(VERSION 3.10)

project(dyn_notes)

set(CMAKE_CXX_STANDARD)

add_executable(main main.cpp dyn_notes.h dyn_notes.cpp)
