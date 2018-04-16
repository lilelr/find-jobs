cmake_minimum_required(VERSION 3.7)
project(find_jobs_algorithms)

set(CMAKE_CXX_STANDARD 11)

set(bit_x_n_power-SRCS x_n_power.cpp)
add_executable(bit_x_n_power ${bit_x_n_power-SRCS})