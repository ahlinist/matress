#include <iostream>
#include <string>
#include <memory>

#include "matrix.hpp"
#include "matrix_processor.hpp"
#include "input_receiver.hpp"

int main(int argc, char *argv[]) {
    matrix::MatrixProcessorImpl matrix_processor;
    input::InputReceiverImpl input_receiver;

    matrix::Matrix matrix = input_receiver.read_matrix_from_file(argv[1]);

    double det = matrix_processor.determinant(matrix.body, matrix.size);
    
    std::cout << "det: " << det << std::endl;
}
