#include "memory_manager.hpp"

#include "matrix.hpp"

void memory::MemoryManagerImpl::cleanup_matrix(const matrix::Matrix &matrix) {
    for (int i = 0; i < matrix.size; ++i) {
        delete[] matrix.body[i];
    }
    delete[] matrix.body;
}

void memory::MemoryManagerImpl::cleanup_matrix(long double** matrix) {
    delete[] matrix[0];
    delete[] matrix;
}
