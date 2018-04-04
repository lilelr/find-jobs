cmake_minimum_required(VERSION 3.7)
project(find_jobs_algorithms)

set(CMAKE_CXX_STANDARD 11)

set(niuniu-package-SRCS niuniu-package-net.cpp)
add_executable(niuniu-package ${niuniu-package-SRCS})

set(niu-niu-find-job-SRCS niu-niu-find-job-net.cpp)
add_executable(niu-niu-find-job ${niu-niu-find-job-SRCS})