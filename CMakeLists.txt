cmake_minimum_required(VERSION 3.5)
project(Cpp_Project)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES  Main.cpp)

add_executable(Cpp_Project ${SOURCE_FILES})