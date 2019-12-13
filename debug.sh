#!/bin/bash

rm ./exec >/dev/null
DEBUG=1 make all -B >/dev/null || make all -B
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./exec
