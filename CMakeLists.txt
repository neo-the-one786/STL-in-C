cmake_minimum_required(VERSION 3.29)
project(STL C)

set(CMAKE_C_STANDARD 23)

add_library(STL STATIC library.c
        include/vector.h
        src/vector.c
        test/test.c
        include/utils.h
        src/utils.c
        src/linked_list.c
        include/linked_list.h
        src/stack.c
        include/stack.h
        include/queue.h
        src/queue.c
        include/deque.h
        src/deque.c
        src/binary_tree.c
        include/binary_tree.h
        include/bst.h
        src/bst.c
        src/unordered_map.c
        include/unordered_map.h
        src/ordered_map.c
        include/ordered_map.h
        src/pair.c
        src/triplet.c
        src/quartet.c
        src/max_heap.c
        include/max_heap.h
        src/min_heap.c
        include/min_heap.h
        src/array.c
        include/array.h
        include/pair.h
        include/triplet.h
        include/quartet.h)
