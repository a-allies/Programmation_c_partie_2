cmake_minimum_required(VERSION 3.17)
project(student C)

set(CMAKE_C_STANDARD 99)
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic-errors")

add_executable(network line_ref.o main.c line.c)
SET_SOURCE_FILES_PROPERTIES(
        line_ref.o
        PROPERTIES
        EXTERNAL_OBJECT true
        GENERATED true
)