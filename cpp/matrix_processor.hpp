#pragma once

#include <memory>

#include "memory_manager.hpp"

namespace matrix {
    class MatrixProcessor {
    public:
        virtual ~MatrixProcessor() {}
        explicit MatrixProcessor(const std::shared_ptr<memory::MemoryManager> memory_manager);
        virtual double determinant2x2(double** matrix) = 0;
        virtual double determinant(double** matrix, const int &size) = 0;
        virtual double** generate_sub_matrix(double** matrix, const int &size, const int &col_to_skip) = 0;
    protected:
        std::shared_ptr<memory::MemoryManager> memory_manager;
    };

    class MatrixProcessorImpl : public MatrixProcessor {
    public:
        using MatrixProcessor::MatrixProcessor;
        virtual double determinant2x2(double** matrix) override;
        virtual double determinant(double** matrix, const int &size) override;
        virtual double** generate_sub_matrix(double** matrix, const int &size, const int &col_to_skip) override;
    };
}
