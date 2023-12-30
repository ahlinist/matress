#include "input_receiver.hpp"
#include "matrix.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <memory>

const char DELIMITER = ',';

int read_matrix_size_from_file(std::ifstream &inputFile);
void validate_matrix(std::ifstream &inputFile, const int &size);
std::ifstream create_file_stream(std::string &file_name);
std::unique_ptr<std::unique_ptr<double[]>[]> allocate_matrix(const int& size);
void populate_matrix(std::ifstream &inputFile, std::unique_ptr<std::unique_ptr<double[]>[]> &matrix, const int& size);

matrix::Matrix input::InputReceiverImpl::read_matrix_from_file(std::string file_name) {
    std::ifstream inputFile = create_file_stream(file_name);
    const int size = read_matrix_size_from_file(inputFile);
    validate_matrix(inputFile, size);
    inputFile.close();
    inputFile.open(file_name);

    std::unique_ptr<std::unique_ptr<double[]>[]> matrix = allocate_matrix(size);
    populate_matrix(inputFile, matrix, size);

    inputFile.close();

    matrix::Matrix result{ size, std::move(matrix) };
    return result;
}

std::unique_ptr<std::unique_ptr<double[]>[]> allocate_matrix(const int& size) {
    std::unique_ptr<std::unique_ptr<double[]>[]> result(new std::unique_ptr<double[]>[size]);

    for (int i = 0; i < size; i++) {
        result[i] = std::make_unique<double[]>(size);
    }

    return result;
}

void populate_matrix(std::ifstream &inputFile, std::unique_ptr<std::unique_ptr<double[]>[]> &matrix, const int& size) {
    std::string line;

    for (int row = 0; row < size; row++) {
        std::getline(inputFile, line);
        std::istringstream iss(line);
        std::string token;

        for (int col = 0; col < size; col++) {
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

int read_matrix_size_from_file(std::ifstream &inputFile) {
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
