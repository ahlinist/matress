#include "memory_manager.hpp"

#include "matrix.hpp"

void memory::MemoryManagerImpl::cleanup_matrix(const matrix::Matrix &matrix) {
    cleanup_matrix(matrix.body, matrix.size);
}

void memory::MemoryManagerImpl::cleanup_matrix(long double** matrix, const int &size) {
    for (int i = 0; i < size; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
