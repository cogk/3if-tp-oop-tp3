#!/bin/bash

rm ./application >/dev/null
DEBUG=1 make -B >/dev/null || make -B
cat test/test1.txt | valgrind ./application
