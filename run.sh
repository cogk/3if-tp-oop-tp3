#!/bin/bash

rm ./application >/dev/null
make -B >/dev/null || make -B
./application
