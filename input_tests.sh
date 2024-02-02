#!/bin/bash

# Number of tests to run

# echo "Starting valid tests for philosophers program..."
# ./philosophers 50 800 2000 2000 7
# ./philosophers 50 800 2000 2000
# ./philosophers 1 1 1 1 1

echo "\nStarting invalid tests for philosophers program..."
# too many philosophers
./philosophers 500 800 2000 2000 7
# not enough arguments
./philosophers 500
./philosophers 500 800
./philosophers 500 800 2000
# wrong numbers for arguments
./philosophers -7 800 2000 2000 7
./philosophers 50 -7 2000 2000 7
./philosophers 50 800 -7 2000 7
./philosophers 50 800 2000 -7 7
./philosophers 50 800 2000 2000 -7
# arguments with 0
./philosophers 0 800 2000 2000 7
./philosophers 50 0 2000 2000 7
./philosophers 50 800 0 2000 7

# wrong chars for arguments
./philosophers a 800 2000 2000 7
./philosophers 50 a 2000 2000 7
./philosophers 50 800 a 2000 7
./philosophers 50 800 2000 a 7
./philosophers 50 800 2000 2000 a
./philosophers 7b 800 2000 2000 7
./philosophers 50 7b 2000 2000 7
./philosophers 50 800 7b 2000 7
./philosophers 50 800 2000 7b 7
./philosophers 50 800 2000 2000 7b
