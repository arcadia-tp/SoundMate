cmake_minimum_required(VERSION 3.13)
project(SoundMate)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_EXE interface/src/main.cpp)
set(SOURCE_LIB interface/src/Models.cpp interface/src/Presentors.cpp interface/src/Views.cpp interface/src/ViewObjects.cpp interface/src/PresentListeners.cpp interface/include/PresentListeners.h interface/src/PresentEvents.cpp interface/include/PresentEvents.h interface/include/ViewObjects.h)

include_directories(interface/include)

add_library(inter STATIC ${SOURCE_LIB})
add_executable(SoundMate ${SOURCE_EXE})

target_link_libraries(SoundMate inter)