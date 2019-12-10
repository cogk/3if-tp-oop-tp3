#!/bin/bash

rm ./application >/dev/null
DEBUG=1 make -B >/dev/null || make -B
cat test/test3.txt | valgrind ./application
