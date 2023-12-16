#include <iostream>
#include <string>
#include <memory>
#include <chrono>

#include "content_formatter.hpp"
#include "memory_manager.hpp"
#include "matrix_processor.hpp"
#include "input_receiver.hpp"

int main() {
    std::shared_ptr<text::ContentFormatter> content_formatter = std::make_shared<text::ContentFormatterImpl>();
    std::shared_ptr<memory::MemoryManager> memory_manager = std::make_shared<memory::MemoryManagerImpl>();
    std::shared_ptr<matrix::MatrixProcessor> matrix_processor = std::make_shared<matrix::MatrixProcessorImpl>(memory_manager);
    std::shared_ptr<input::InputReceiver> input_receiver = std::make_shared<input::InputReceiverImpl>();

    int size = input_receiver->read_matrix_size();
    double** matrix = input_receiver->read_matrix(size);

    std::string matrix_str = content_formatter->format_matrix(matrix, size);
    std::cout << "matrix: \n" << matrix_str << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    double det = matrix_processor->determinant(matrix, size);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;

    std::cout << "det: " << det << std::endl;

    memory_manager->cleanup_matrix(matrix, size);
}
