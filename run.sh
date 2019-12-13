#!/bin/bash

rm ./exec >/dev/null
make -B >/dev/null || make -B
valgrind ./exec
