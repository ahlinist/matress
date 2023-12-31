#pragma once

#include <iostream>
#include <string>

#include "matrix.hpp"

namespace input {
    class InputReceiver {
    public:
        virtual ~InputReceiver() {}
        virtual matrix::Matrix read_matrix_from_file(std::string file_name) = 0;
    };

    class InputReceiverImpl : public InputReceiver {
    public:
        virtual matrix::Matrix read_matrix_from_file(std::string file_name) override;
    };
}
