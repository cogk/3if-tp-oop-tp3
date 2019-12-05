#!/bin/bash

rm ./application >/dev/null
DEBUG=1 make -B >/dev/null || make -B
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./application
