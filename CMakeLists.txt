cmake_minimum_required(VERSION 3.23)
project(linked_list)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(linked_list
        linked_list.cpp
        linked_list.h
        main.cpp
        node.cpp
        node.h shortJob.h shortJob.cpp)
