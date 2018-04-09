cmake_minimum_required(VERSION 3.7)
project(find_jobs_algorithms)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(hash)
add_subdirectory(greedy)
add_subdirectory(classic_algorithms_learning)
set(SOURCE_FILES main.cpp)
add_executable(main ${SOURCE_FILES})

