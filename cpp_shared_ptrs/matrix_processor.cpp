#include "matrix_processor.hpp"

#include <memory>

#include "matrix.hpp"

std::shared_ptr<long double*[]> allocate_sub_matrix(const int& size);
void populate_sub_matrix(std::shared_ptr<long double*[]> matrix, std::shared_ptr<long double*[]> sub_matrix, const int& size, const int& col_to_skip);
long double determinant(std::shared_ptr<long double*[]> matrix, const int& size);
long double determinant2x2(std::shared_ptr<long double*[]> matrix);

long double matrix::MatrixProcessorImpl::determinant(const matrix::Matrix &matrix) {
    return determinant(matrix.body, matrix.size);
}

long double matrix::MatrixProcessorImpl::determinant(std::shared_ptr<long double*[]> matrix, const int& size) {
    if (size == 2) {
        return determinant2x2(matrix);
    }

    int sign = 1;
    long double result = 0;
    int next_size = size - 1;

    std::shared_ptr<long double*[]> sub_matrix(allocate_sub_matrix(size));

    for (int col_to_skip = 0; col_to_skip < size; col_to_skip++) {
        populate_sub_matrix(matrix, sub_matrix, size, col_to_skip);
        result += sign * matrix[0][col_to_skip] * determinant(sub_matrix, next_size);
        sign = -sign;
    }

    return result;
}

long double determinant2x2(std::shared_ptr<long double*[]> matrix) {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

std::shared_ptr<long double*[]> allocate_sub_matrix(const int& size) {
    std::shared_ptr<long double*[]> result(new long double*[size]);
    result[0] = new long double[(size - 1) * (size - 1)];

    for (int i = 1; i < size; i++) {
        result[i] = result[0] + i * (size - 1);
    }

    return result;
}

void populate_sub_matrix(std::shared_ptr<long double*[]> matrix, std::shared_ptr<long double*[]> sub_matrix, const int& size, const int& col_to_skip) {
    for (int row = 0; row < size - 1; row++) {
        for (int col = 0, sub_col = 0; col < size; col++) {
            if (col == col_to_skip) {
                continue;
            }

            sub_matrix[row][sub_col++] = matrix[row + 1][col];
        }
    }
}
