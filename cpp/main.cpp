#include <iostream>
#include <sstream>
#include <string>

double determinant2x2(double** matrix);

double determinant(double** matrix, int size);

std::string format_matrix(double** matrix, int size);

void cleanup(double** matrix, int size);

double** generate_sub_matrix(double** matrix, int size, int col_to_skip);

int main() {
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

    std::string matrix_str = format_matrix(matrix, size);
    std::cout << "matrix: \n" << matrix_str << std::endl;

    double det = determinant(matrix, size);
    std::cout << "det: " << det << std::endl;

    cleanup(matrix, size);
}

double determinant2x2(double** matrix) {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

double determinant(double** matrix, int size) {
    if (size > 2) {
        int sign = 1;
        double result = 0;
        int next_size = size - 1;

        for (int col_to_skip = 0; col_to_skip < size; col_to_skip++) {
            double** sub_matrix = generate_sub_matrix(matrix, size, col_to_skip);
            result += sign * matrix[0][col_to_skip] * determinant(sub_matrix, next_size);
            cleanup(sub_matrix, next_size); //do we need to cleanup? mb yes bc of "new" kw?
            sign = -sign;
        }
        
        return result;
    } else {
        return determinant2x2(matrix);
    }
}

std::string format_matrix(double** matrix, int size) {
    std::stringstream sstm{};

    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            sstm << matrix[row][col] << "\t";
        }

        sstm << "\n";
    }

    return sstm.str();
}

void cleanup(double** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

double** generate_sub_matrix(double** matrix, int size, int col_to_skip) {
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
