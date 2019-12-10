#!/bin/bash

rm ./application >/dev/null
DEBUG=1 make -B >/dev/null || make -B

for f in test/*; do
  echo "--------------------------------------------------------------------------------"
  echo "$f"
  cat "$f" | valgrind ./application
done

