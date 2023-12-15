#include <iostream>
#include <string>
#include <memory>

#include "content_formatter.hpp"
#include "memory_manager.hpp"
#include "matrix_processor.hpp"

int main() {
    std::shared_ptr<text::ContentFormatter> content_formatter = std::make_shared<text::ContentFormatterImpl>();
    std::shared_ptr<memory::MemoryManager> memory_manager = std::make_shared<memory::MemoryManagerImpl>();
    std::shared_ptr<matrix::MatrixProcessor> matrix_processor = std::make_shared<matrix::MatrixProcessorImpl>(memory_manager);

    int size = 4;

    double** matrix = new double*[size];
    for (int row = 0; row < size; row++) {
        matrix[row] = new double[size];
    }
    matrix[0][0] = 1;
    matrix[0][1] = 3;
    matrix[0][2] = 1;
    matrix[0][3] = 2;
    matrix[1][0] = 4;
    matrix[1][1] = 2;
    matrix[1][2] = 1;
    matrix[1][3] = 3;
    matrix[2][0] = 6;
    matrix[2][1] = 2;
    matrix[2][2] = 1;
    matrix[2][3] = 3;
    matrix[3][0] = 1;
    matrix[3][1] = 6;
    matrix[3][2] = 2;
    matrix[3][3] = 2;

    std::string matrix_str = content_formatter->format_matrix(matrix, size);
    std::cout << "matrix: \n" << matrix_str << std::endl;

    double det = matrix_processor->determinant(matrix, size);
    std::cout << "det: " << det << std::endl;

    memory_manager->cleanup_matrix(matrix, size);
}
