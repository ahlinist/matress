#include "matrix_processor.hpp"

#include <memory>

#include "memory_manager.hpp"

matrix::MatrixProcessor::MatrixProcessor(const std::shared_ptr<memory::MemoryManager> memory_manager) 
    : memory_manager{ memory_manager} {} 

double matrix::MatrixProcessorImpl::determinant2x2(double** matrix) {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

double matrix::MatrixProcessorImpl::determinant(double** matrix, const int &size) {
    if (size > 2) {
        int sign = 1;
        double result = 0;
        int next_size = size - 1;

        for (int col_to_skip = 0; col_to_skip < size; col_to_skip++) {
            double** sub_matrix = generate_sub_matrix(matrix, size, col_to_skip);
            result += sign * matrix[0][col_to_skip] * determinant(sub_matrix, next_size);
            memory_manager->cleanup_matrix(sub_matrix, next_size); //do we need to cleanup? mb yes bc of "new" kw?
            sign = -sign;
        }
        
        return result;
    } else {
        return determinant2x2(matrix);
    }
}

double** matrix::MatrixProcessorImpl::generate_sub_matrix(double** matrix, const int &size, const int &col_to_skip) {
    double** result = new double*[size - 1];

    for (int row = 0; row < size - 1; row++) {
        result[row] = new double[size - 1];

        for (int col = 0; col < size; col++) {
            if (col < col_to_skip) {
                result[row][col] = matrix[row + 1][col];
            } else if (col == col_to_skip) {
                continue;
            } else {
                result[row][col-1] = matrix[row + 1][col];
            }
        }
    }

    return result;
}
