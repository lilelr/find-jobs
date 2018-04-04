cmake_minimum_required(VERSION 3.7)
project(find_jobs_algorithms)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(hash)
add_subdirectory(greedy)
set(SOURCE_FILES main.cpp)
add_executable(main ${SOURCE_FILES})

set(main1_SRCS main1.cpp)
add_executable(main1 ${main1_SRCS})