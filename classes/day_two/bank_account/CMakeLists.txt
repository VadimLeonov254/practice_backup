cmake_minimum_required(VERSION 3.10)

project(bank_account)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp bank_account.h bank_account.cpp)
