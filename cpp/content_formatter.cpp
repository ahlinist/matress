#include "content_formatter.hpp"

#include <string>
#include <sstream>

#include "matrix.hpp"

std::string text::ContentFormatterImpl::format_matrix(const matrix::Matrix &matrix) {
    long double** body = matrix.body;
    const int size = matrix.size;
    std::stringstream sstm{};

    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            sstm << body[row][col] << "\t";
        }

        sstm << "\n";
    }

    return sstm.str();
}
