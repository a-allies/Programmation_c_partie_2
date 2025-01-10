cmake_minimum_required(VERSION 3.30)
project(TP9 C)

set(CMAKE_C_STANDARD 90)

add_executable(TP9 main.c edgeList.o edgeList.h graph.o graph.h vertexList.o vertexList.h dijkstra.c dijkstra.h )
