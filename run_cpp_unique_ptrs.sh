# Start measuring execution time
start_time=$(date +%s.%N)

# Your script commands here
valgrind --tool=massif --massif-out-file=main_cpp_unique_ptrs.out ./main_cpp_unique_ptrs input.txt

# End measuring execution time
end_time=$(date +%s.%N)
execution_time=$(echo "$end_time - $start_time" | bc)

# Print execution time
echo "Execution time for cpp_unique_ptrs: $execution_time seconds"
