cmake_minimum_required(VERSION 3.10)

project(doc)

set(CMAKE_CXX_STANDARD 17)

include_directories(headers)

set(SOURCE
    src/Document.cpp
    src/EditorSession.cpp
    src/User.cpp
    src/main.cpp)

add_executable(main ${SOURCE})
