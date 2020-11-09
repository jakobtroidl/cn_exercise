cmake_minimum_required(VERSION 3.17)
project(cn_task20)

set(CMAKE_CXX_STANDARD 17)

include_directories(/Users/jakob.troidl/Desktop/eigen)
include_directories(/Users/jakob.troidl/Desktop/blaze)

add_executable(cn_task20 eigen.cpp blaze.cpp main.cpp eigen.h blaze.h)