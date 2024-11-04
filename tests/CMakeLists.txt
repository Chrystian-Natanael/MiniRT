cmake_minimum_required(VERSION 3.6)
project(tests)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(../includes)
include_directories(../libs/libft/includes)
include_directories(../libs/MLX42/include)
include_directories(../libs/garbage-collector/include)
include_directories(googletest/include)

add_subdirectory(googletest)
enable_testing()

set(TESTS_FOLDER my_tests)
file(GLOB_RECURSE TESTS_FILES "${TESTS_FOLDER}/*.cpp")
message(STATUS "Tests files: ${TESTS_FILES}")

set(PROJECT_SRC_FOLDER "../src")
file(GLOB_RECURSE PROJECT_SRC_FILES "${PROJECT_SRC_FOLDER}/**/*.c")
list(FILTER PROJECT_SRC_FILES EXCLUDE REGEX ".*main.c$")
message(STATUS "project files: ${PROJECT_SRC_FILES}")

add_executable(run_tests ${PROJECT_SRC_FILES} ${TESTS_FILES})

target_link_libraries(run_tests gtest gtest_main
	${CMAKE_SOURCE_DIR}/../libs/libft/libft.a
	${CMAKE_SOURCE_DIR}/../libs/MLX42/build/libmlx42.a
	${CMAKE_SOURCE_DIR}/../libs/garbage-collector/garbage_collector.a
)

include(GoogleTest)
gtest_discover_tests(run_tests)
