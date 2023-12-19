#include <sys/resource.h>

#include <iostream>
#include <string>
#include <memory>
#include <chrono>

#include "matrix_processor.hpp"
#include "input_receiver.hpp"

void print_memory_usage();

int main(int argc, char *argv[]) {
    print_memory_usage();

    matrix::MatrixProcessorImpl matrix_processor;
    input::InputReceiverImpl input_receiver;

    matrix::Matrix matrix = input_receiver.read_matrix_from_file(argv[1]);

    auto start = std::chrono::high_resolution_clock::now();

    long double det = matrix_processor.determinant(matrix);
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;

    std::cout << "det: " << det << std::endl;

    print_memory_usage();
}

void print_memory_usage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    std::cout << "Memory Usage: " << usage.ru_maxrss << " KB" << std::endl;
}
