cmake_minimum_required(VERSION 3.17)
project(image-square C)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra ")

add_executable(main main.c image.c image-proba.c test.c)
target_link_libraries(main m)