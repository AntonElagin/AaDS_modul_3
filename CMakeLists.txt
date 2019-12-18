cmake_minimum_required(VERSION 3.15)
project(AaDS_M3)

set(CMAKE_CXX_STANDARD 14)
include_directories(task1)
add_executable(AaDS_task1
        task1/main.cpp
        task1/IGraph.h
        task1/ListGraph.cpp
        task1/ListGraph.h
        task1/MatrixGraph.cpp
        task1/MatrixGraph.h
        task1/SetGraph.cpp
        task1/SetGraph.h
        task1/ArcGraph.cpp
        task1/ArcGraph.h)

include_directories(task2)
add_executable(AaDS_task2
        task2/graph_2.cpp)

include_directories(task3)
add_executable(AaDS_task3
        task3/main.cpp)