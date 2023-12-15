#include "content_formatter.hpp"

#include <string>
#include <sstream>

std::string text::ContentFormatterImpl::format_matrix(double** matrix, const int &size) {
    std::stringstream sstm{};

    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            sstm << matrix[row][col] << "\t";
        }

        sstm << "\n";
    }

    return sstm.str();
}
