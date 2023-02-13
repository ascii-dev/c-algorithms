cmake_minimum_required(VERSION 3.5)

project(binary_search_proj)

set(SOURCE_FILES test.c binary_search.c)
add_executable(binary_search.o ${SOURCE_FILES})
