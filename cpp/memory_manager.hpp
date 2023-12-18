#pragma once

#include "matrix.hpp"

namespace memory {
    class MemoryManager {
    public:
        virtual ~MemoryManager() {}
        virtual void cleanup_matrix(const matrix::Matrix &matrix) = 0;
        virtual void cleanup_matrix(long double** matrix) = 0;
    };

    class MemoryManagerImpl : public MemoryManager {
    public:
        virtual void cleanup_matrix(const matrix::Matrix &matrix) override;
        virtual void cleanup_matrix(long double** matrix) override;
    };
}
