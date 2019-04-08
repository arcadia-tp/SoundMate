cmake_minimum_required(VERSION 3.10)
project(server_tests)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")

set(PROJECT_ROOT ../)

set(TEST_ROOT .)

set(INCLUDE ${TEST_ROOT}/include)

set(GMOCK_DIR ${PROJECT_ROOT}/shared_files/googletest/googlemock/)

set(SOURCE_LIB ${INCLUDE}/test_parser.cpp)

set(SRC ../src/client_connection.cpp ../src/cl_parser.cpp ../src/query_processor.cpp 
      ../src/data_base_query.cpp)

#set(SRC ../src/${})

set(TEST_SRC ./src/test_cl_parser.cpp ./src/test_client_connection.cpp 
      ./src/test_query_processor.cpp ./src/test_data_base_query)

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


