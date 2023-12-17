#pragma once

#include <memory>

#include "memory_manager.hpp"
#include "matrix.hpp"

namespace matrix {
    class MatrixProcessor {
    public:
        virtual ~MatrixProcessor() {}
        explicit MatrixProcessor(const std::shared_ptr<memory::MemoryManager> memory_manager);
        virtual long double determinant(const matrix::Matrix &matrix) = 0;
    protected:
        std::shared_ptr<memory::MemoryManager> memory_manager;
        virtual long double determinant2x2(long double** matrix) = 0;
        virtual long double determinant(long double** matrix, const int &size) = 0;
        virtual long double** generate_sub_matrix(long double** matrix, const int &size, const int &col_to_skip) = 0;
    };

    class MatrixProcessorImpl : public MatrixProcessor {
    public:
        using MatrixProcessor::MatrixProcessor;
        virtual long double determinant(const matrix::Matrix &matrix) override;
    protected:
        virtual long double determinant2x2(long double** matrix) override;
        virtual long double determinant(long double** matrix, const int &size) override;
        virtual long double** generate_sub_matrix(long double** matrix, const int &size, const int &col_to_skip) override;
    };
}
