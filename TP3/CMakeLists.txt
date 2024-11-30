cmake_minimum_required(VERSION 3.17)
project(imageRGB C)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra ")

add_executable(main main.c imageRGB.c test.c BMPFile_teacher.o)