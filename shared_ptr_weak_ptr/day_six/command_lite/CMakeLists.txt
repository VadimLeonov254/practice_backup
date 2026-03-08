cmake_minimum_required(VERSION 3.10)

project(command_lite)

set(CMAKE_CXX_STANDARD 17)

include_directories(headers)

set(SOURCES
    src/AddTaskCommand.cpp
    src/DeleteTaskCommand.cpp
    src/TaskManager.cpp
    src/UndoManager.cpp
    src/main.cpp)

add_executable(main ${SOURCES})
