cmake_minimum_required(VERSION 3.30)
project(leakDetector C)

set(CMAKE_C_STANDARD 90)

add_executable(leakDetector main.c myAlloc.c myFunctions.c memoryList.c test.c)
