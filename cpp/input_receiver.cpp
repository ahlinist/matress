#include "input_receiver.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <memory>

#include "matrix.hpp"

const char DELIMITER = ',';

int first_line_length(std::ifstream &inputFile);
void validate_matrix(std::ifstream &inputFile, const int &size);
std::ifstream create_file_stream(std::string &file_name);
std::shared_ptr<long double*[]> allocate_matrix(const int& size);
void populate_matrix(std::ifstream &inputFile, std::shared_ptr<long double*[]> matrix, const int& size);

matrix::Matrix input::InputReceiverImpl::read_matrix_from_terminal() {
    int size = read_matrix_size_from_terminal();
    std::shared_ptr<long double*[]> matrix = read_matrix_body_from_terminal(size);
    matrix::Matrix result{ size, matrix };
    return result;
}

int input::InputReceiverImpl::read_matrix_size_from_terminal() {
    std::cout << "Enter matrix size: ";
    int matrix_size;
    std::cin >> matrix_size;
    return matrix_size;
}

std::shared_ptr<long double*[]> input::InputReceiverImpl::read_matrix_body_from_terminal(const int &size) {
    std::shared_ptr<long double*[]> matrix(new long double*[size]);

    for (int row = 0; row < size; row++) {
        matrix[row] = new long double[size];
        std::cout << "Enter elements of row " << row + 1 << ": " << std::endl;

        for (int col = 0; col < size; col++) {
            std::cin >> matrix[row][col];
        }
    }

    return matrix;
}

matrix::Matrix input::InputReceiverImpl::read_matrix_from_file(std::string file_name) {
    std::ifstream inputFile = create_file_stream(file_name);
    const int size = first_line_length(inputFile);
    validate_matrix(inputFile, size);
    inputFile.close();
    inputFile.open(file_name);

    std::shared_ptr<long double*[]> matrix(allocate_matrix(size));
    populate_matrix(inputFile, matrix, size);

    inputFile.close();

    matrix::Matrix result{ size, matrix };
    return result;
}

std::shared_ptr<long double*[]> allocate_matrix(const int& size) {
    std::shared_ptr<long double*[]> result(new long double*[size + 1]);
    result[0] = new long double[(size) * (size)];

    for (int i = 0; i < size; i++) {
        result[i] = result[0] + i * size;
    }

    return result;
}

void populate_matrix(std::ifstream &inputFile, std::shared_ptr<long double*[]> matrix, const int& size) {
    std::string line;

    for (int row = 0; row < size; row++) {
        std::getline(inputFile, line);
        std::istringstream iss(line);
        std::string token;
        
        for (int col = 0, sub_col = 0; col < size; col++) {
            std::getline(iss, token, DELIMITER);
            matrix[row][col] = std::stold(token);
        }
    }
}

std::ifstream create_file_stream(std::string &file_name) {
    std::ifstream inputFile(file_name);

    if (!inputFile.is_open()) {
        throw std::invalid_argument("Error opening the file.");
    }

    return inputFile;
}

int first_line_length(std::ifstream &inputFile) {
    std::string first_line;
    std::getline(inputFile, first_line);
    std::istringstream iss(first_line);
    std::string token;
    std::vector<std::string> tokens;

    while (std::getline(iss, token, DELIMITER)) {
        tokens.push_back(token);
    }

    return tokens.size();
}

void validate_matrix(std::ifstream &inputFile, const int &size) {
    std::string line;
    int line_number = 1;

    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string token;
        std::vector<std::string> tokens;

        while (std::getline(iss, token, DELIMITER)) {
            tokens.push_back(token);
        }

        int current_row_length = tokens.size();

        if ((line_number == size)) {
            if (current_row_length != 0) {
                std::string message = "Matrix size is supposed to be " + std::to_string(size) + 
                    "x" + std::to_string(size) + " but there's row number " + std::to_string(line_number + 1) + " found.";
                throw std::invalid_argument(message);
            }
            break;
        }

        if (current_row_length != size) {
            std::string message = "Row number " + std::to_string(line_number + 1) + " contains " + 
                std::to_string(current_row_length) + " elements instead of " + std::to_string(size) + " as in the 1-st one.";
            throw std::invalid_argument(message);
        }

        line_number++;
    }
}
