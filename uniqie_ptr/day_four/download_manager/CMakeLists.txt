cmake_minimum_required(VERSION 3.10)

project(download_manager)

set(CMAKE_CXX_STANDARD 17)

include_directories(headers)

set(SOURCES
    src/DownloadManager.cpp
    src/DownloadingState.cpp
    src/FailState.cpp
    src/IdleState.cpp
    src/PauseState.cpp
    src/main.cpp)

add_executable(main ${SOURCES})
