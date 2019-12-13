#!/bin/bash

rm ./exec >/dev/null
DEBUG=1 make all -B >/dev/null || make all -B

for f in tests/*; do
  echo "--------------------------------------------------------------------------------"
  echo "$f"
  echo
  cat "$f" | valgrind ./exec
done
