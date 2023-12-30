#pragma once

#include <memory>

namespace matrix {
    class MatrixProcessor {
    public:
        virtual ~MatrixProcessor() {}
        virtual double determinant(std::unique_ptr<std::unique_ptr<double[]>[]> matrix, const int& size) = 0;
    };

    class MatrixProcessorImpl : public MatrixProcessor {
    public:
        virtual double determinant(std::unique_ptr<std::unique_ptr<double[]>[]> matrix, const int& size) override;
    };
}
