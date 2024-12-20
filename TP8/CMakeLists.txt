cmake_minimum_required(VERSION 3.20)
project(huffman C)

set(CMAKE_C_STANDARD 90)

add_executable(main-Huffman main-Huffman.c binary_tree.c image.c list-teacher.o huffman_method-teacher.o image-proba.c)
target_link_libraries(main-Huffman m)