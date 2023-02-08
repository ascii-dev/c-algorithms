cmake_minimum_required(VERSION 3.5)

project(queues_proj)

set(SOURCE_FILES test.c linked_queue.c circular_buffer.c)
add_executable(queues.o ${SOURCE_FILES})
