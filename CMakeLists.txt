cmake_minimum_required(VERSION 3.13)
project(SoundMate)

set(CMAKE_CXX_STANDARD 17)

include_directories(interface/include)

add_executable(SoundMate interface/src/main.cpp)