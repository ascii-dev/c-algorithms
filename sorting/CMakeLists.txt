cmake_minimum_required(VERSION 3.5)

project(sorting_proj)

set(SOURCE_FILES test.c merge_sort.c quick_sort.c)
add_executable(sort.o ${SOURCE_FILES})
