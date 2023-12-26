#!/bin/bash

#Compile
g++ -g cpp/* -o main_cpp

# Start measuring execution time
start_time=$(date +%s.%N)

# Your script commands here
valgrind --tool=massif --massif-out-file=main_cpp.out ./main_cpp input.txt

# End measuring execution time
end_time=$(date +%s.%N)
execution_time=$(echo "$end_time - $start_time" | bc)

# Print execution time
echo "Execution time: $execution_time seconds"
