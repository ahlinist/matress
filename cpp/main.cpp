#include <iostream>
#include <string>
#include <memory>

#include "memory_manager.hpp"
#include "matrix_processor.hpp"
#include "input_receiver.hpp"

int main(int argc, char *argv[]) {
    std::shared_ptr<memory::MemoryManager> memory_manager = std::make_shared<memory::MemoryManagerImpl>();
    std::shared_ptr<matrix::MatrixProcessor> matrix_processor = std::make_shared<matrix::MatrixProcessorImpl>(memory_manager);
    std::shared_ptr<input::InputReceiver> input_receiver = std::make_shared<input::InputReceiverImpl>();

    matrix::Matrix matrix = input_receiver-> read_matrix_from_file(argv[1]);

    long double det = matrix_processor->determinant(matrix);

    std::cout << "det: " << det << std::endl;
    
    memory_manager->cleanup_matrix(matrix);
}
