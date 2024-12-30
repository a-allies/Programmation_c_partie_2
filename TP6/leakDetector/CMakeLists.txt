cmake_minimum_required(VERSION 3.30)
project(2_A_memoryList C)

set(CMAKE_C_STANDARD 90)

add_executable(memoryList main.c memoryList.c test.c myAlloc.c myFunctions.c)
