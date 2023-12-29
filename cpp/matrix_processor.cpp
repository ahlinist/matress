#include "matrix_processor.hpp"

void transform(double** matrix, const int& size);

double matrix::MatrixProcessorImpl::determinant(double** matrix, const int &size) {
    transform(matrix, size);

    double result = 1;

    for (int diag = 0; diag < size; diag++) {
        result *= matrix[diag][diag];
    }

    return result;
}

void transform(double** matrix, const int& size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i; k < size; k++) {
                matrix[j][k] = matrix[j][k] - factor * matrix[i][k];
            }
        }
    }
}
