#pragma once

namespace matrix {
    class MatrixProcessor {
    public:
        virtual ~MatrixProcessor() {}
        virtual double determinant(double** matrix, const int &size) = 0;
    };

    class MatrixProcessorImpl : public MatrixProcessor {
    public:
        virtual double determinant(double** matrix, const int &size) override;
    };
}
