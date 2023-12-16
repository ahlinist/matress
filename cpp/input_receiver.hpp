#pragma once

#include <iostream>

namespace input {
    class InputReceiver {
    public:
        virtual ~InputReceiver() {}
        virtual int read_matrix_size() = 0;
        virtual long double** read_matrix(const int &size) = 0;
    };

    class InputReceiverImpl : public InputReceiver {
    public:
        virtual int read_matrix_size() override;
        virtual long double** read_matrix(const int &size) override;
    };
}
