#!/bin/bash

rm ./application >/dev/null
make >/dev/null || make
./application
