#! /usr/bin/bash


set -xe

cc -Wextra -Wall test_stack.c       -o ./executables/test_stack
cc -Wextra -Wall test_queue.c       -o ./executables/test_queue
cc -Wextra -Wall test_window_iter.c -o ./executables/test_window_iter
cc -Wextra -Wall test_matrix.c      -o ./executables/test_matrix

