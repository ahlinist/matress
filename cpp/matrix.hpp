#pragma once

#include <memory>

namespace matrix {
    struct Matrix {
        int size;
        std::shared_ptr<long double*[]> body;
    };
}
