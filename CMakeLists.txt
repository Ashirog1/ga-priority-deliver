cmake_minimum_required(VERSION 3.24)
project(ga_priority_deliver)

set(CMAKE_CXX_STANDARD 20)

add_executable(ga_priority_deliver include/constants.h include/customer.h include/route.h src/route.cpp include/utils.h src/utils.cpp main.cpp src/constants.cpp src/customer.cpp include/solution.h src/solution.cpp include/population.h include/chromosome.h include/mcf.h src/mcf.cpp include/route_set.h src/route_set.cpp)
