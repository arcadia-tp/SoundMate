cmake_minimum_required(VERSION 3.10)
project(server_tests)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -pthread")

set(PROJECT_ROOT ../)

set(TEST_ROOT .)

set(INCLUDE ${TEST_ROOT}/include)

set(GMOCK_DIR ${PROJECT_ROOT}/shared_files/googletest/googlemock/)

set(SRC ../src/cl_parser.cpp ../src/db_parser.cpp ../src/query_processor.cpp)

set(TEST_SRC ./src/test_cl_parser.cpp ./src/test_db_parser.cpp ./src/test_query_processor.cpp)


SET(Boost_USE_STATIC_LIBS OFF)
SET(Boost_USE_MULTITHREAD ON)

FIND_PACKAGE(Boost REQUIRED COMPONENTS system thread regex)
IF(Boost_FOUND)
  INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
  LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
ENDIF(Boost_FOUND)

SET(USED_LIBS ${Boost_SYSTEM_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_REGEX_LIBRARY})


include_directories(SYSTEM ${GTEST_DIR}/include ${GTEST_DIR})
include_directories(SYSTEM ${GMOCK_DIR}/include ${GMOCK_DIR}/gtest/include)
include_directories("${PROJECT_ROOT}/include")
include_directories("include/")
include_directories("src/")



add_executable(tests  ${SRC} ${TEST_SRC} ./tests.cpp)


find_package(GTest REQUIRED)

target_link_libraries(tests gtest gtest_main pthread)
target_link_libraries(tests gmock gmock_main)
target_link_libraries(tests ${USED_LIBS})


