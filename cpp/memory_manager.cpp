#include "memory_manager.hpp"

void memory::MemoryManagerImpl::cleanup_matrix(double** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
