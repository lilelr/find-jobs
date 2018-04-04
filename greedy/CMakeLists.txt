cmake_minimum_required(VERSION 3.7)
project(find_jobs_algorithms)

set(CMAKE_CXX_STANDARD 11)

set(position-lamp-net-SRCS positon-lamp-net.cpp)
add_executable(position-lamp-net ${position-lamp-net-SRCS})