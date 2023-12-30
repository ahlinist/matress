#pragma once

#include <memory>

namespace matrix {
    struct Matrix {
        int size;
        std::unique_ptr<std::unique_ptr<double[]>[]> body;
    };
}