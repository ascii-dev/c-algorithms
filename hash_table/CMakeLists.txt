cmake_minimum_required(VERSION 3.5)

project(arrays_proj)

set(SOURCE_FILES test.c hash_table.c)
add_executable(hash_table.o ${SOURCE_FILES})
