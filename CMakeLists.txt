cmake_minimum_required(VERSION 3.24)
project(ga_priority_deliver)

set(CMAKE_CXX_STANDARD 17)

add_executable(ga_priority_deliver main.cpp include/constants.h include/customer.h src/customer.cpp)
