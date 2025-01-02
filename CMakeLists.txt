cmake_minimum_required(VERSION 3.16)

project(project_setup)

set(CMAKE_CXX_STANDARD_REQUIRED 20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wpedantic -Wextra -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -fsanitize=address,undefined")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/generators")

find_package(GTest REQUIRED)

include_directories(include)

file(GLOB srcs src/*.cpp)
add_executable(${CMAKE_PROJECT_NAME} ${srcs})

file(GLOB tests tests/*.cpp)
add_executable(${CMAKE_PROJECT_NAME}-tests ${srcs} ${tests})
target_link_libraries(${CMAKE_PROJECT_NAME}-tests GTest::gtest GTest::gmock)

enable_testing()
include(GoogleTest)
gtest_discover_tests(${CMAKE_PROJECT_NAME}-tests)
