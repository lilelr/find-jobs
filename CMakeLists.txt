cmake_minimum_required(VERSION 3.7)
project(find_jobs_algorithms)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(hash)
add_subdirectory(greedy)
add_subdirectory(bit)
set(SOURCE_FILES main.cpp)
add_executable(main ${SOURCE_FILES})


set(main1_FILES main1.cpp)
add_executable(main1 ${main1_FILES})

set(main3_FILES main3.cpp)
add_executable(main3 ${main3_FILES})
