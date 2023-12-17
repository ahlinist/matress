#pragma once

#include <iostream>
#include <string>

#include "matrix.hpp"

namespace input {
    class InputReceiver {
    public:
        virtual ~InputReceiver() {}
        virtual int read_matrix_size_from_terminal() = 0;
        virtual matrix::Matrix read_matrix_from_terminal(const int &size) = 0;
        virtual matrix::Matrix read_matrix_from_file(std::string file_name) = 0;
    };

    class InputReceiverImpl : public InputReceiver {
    public:
        virtual int read_matrix_size_from_terminal() override;
        virtual matrix::Matrix read_matrix_from_terminal(const int &size) override;
        virtual matrix::Matrix read_matrix_from_file(std::string file_name) override;
    };
}
