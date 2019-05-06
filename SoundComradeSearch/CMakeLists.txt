cmake_minimum_required(VERSION 3.10)
project(myProject)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")

set(PROJECT_ROOT .)


#set(SRC ./src/${})

set(SRC ./src/server.cpp ./src/client_connection.cpp ./src/request.cpp ./src/cl_parser.cpp)

SET(Boost_USE_STATIC_LIBS OFF)
SET(Boost_USE_MULTITHREAD ON)

FIND_PACKAGE(Boost 1.55.0 REQUIRED COMPONENTS system filesystem thread regex)
IF(Boost_FOUND)
  INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
  LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
ENDIF(Boost_FOUND)

SET(USED_LIBS ${Boost_SYSTEM_LIBRARY} ${Boost_FILESYSTEM_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_REGEX_LIBRARY})

include_directories("include/")

include_directories("src/")

add_library(Net src/server.cpp)

add_executable(main  ${SRC} ./main.cpp)


target_link_libraries(main  pthread)
target_link_libraries(main ${Boost_LIBRARIES})
target_link_libraries(main ${USED_LIBS} Net)

#############################################

#cmake_minimum_required(VERSION 3.13)
#project(myProject)

#set(CMAKE_CXX_STANDARD 11)
#add_executable(myProject main.cpp)

#find_package(Boost 1.58.0 REQUIRED COMPONENTS system filesystem)
#target_link_libraries(myProject ${Boost_LIBRARIES})
