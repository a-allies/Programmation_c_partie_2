cmake_minimum_required(VERSION 3.20)
project(player-multimedia C)

set(CMAKE_C_STANDARD 90)

add_executable(testlist main_testlist.c multimedia-object.c test.c listMO.c)
