#include "input_receiver.hpp"

#include <iostream>

int input::InputReceiverImpl::read_matrix_size() {
    std::cout << "Enter matrix size: ";
    int matrix_size;
    std::cin >> matrix_size;
    return matrix_size;
}

long double** input::InputReceiverImpl::read_matrix(const int &size) {
    long double** matrix = new long double*[size];

    for (int row = 0; row < size; row++) {
        matrix[row] = new long double[size];
        std::cout << "Enter elements of row " << row + 1 << ": " << std::endl;

        for (int col = 0; col < size; col++) {
            std::cin >> matrix[row][col];
        }
    }

    return matrix;
}
