#pragma once

#include <memory>

#include "matrix.hpp"

namespace matrix {
    class MatrixProcessor {
    public:
        virtual ~MatrixProcessor() {}
        virtual long double determinant(const matrix::Matrix &matrix) = 0;
    protected:
        virtual long double determinant(std::shared_ptr<long double*[]> matrix, const int& size) = 0;
    };

    class MatrixProcessorImpl : public MatrixProcessor {
    public:
        virtual long double determinant(const matrix::Matrix &matrix) override;
    protected:
        virtual long double determinant(std::shared_ptr<long double*[]> matrix, const int& size) override;
    };
}
