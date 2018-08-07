cmake_minimum_required(VERSION 3.7)
project(find_jobs_algorithms)

set(CMAKE_CXX_STANDARD 11)

set(pinduoduo_maze_path-SRCS pinduoduo_maze_path.cpp)
add_executable(pinduoduo_maze_path ${pinduoduo_maze_path-SRCS})

set(toutiao_maze_push_block-SRCS toutiao_maze_push_block.cpp)
add_executable(toutiao_maze_push_block ${toutiao_maze_push_block-SRCS})