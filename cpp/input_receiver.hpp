#pragma once

#include <iostream>
#include <string>

namespace input {
    class InputReceiver {
    public:
        virtual ~InputReceiver() {}
        virtual int read_matrix_size_from_terminal() = 0;
        virtual int read_matrix_size_from_file(std::string file_name) = 0;
        virtual long double** read_matrix_from_terminal(const int &size) = 0;
        virtual long double** read_matrix_from_file(std::string file_name, const int &size) = 0;
    };

    class InputReceiverImpl : public InputReceiver {
    public:
        virtual int read_matrix_size_from_terminal() override;
        virtual int read_matrix_size_from_file(std::string file_name) override;
        virtual long double** read_matrix_from_terminal(const int &size) override;
        virtual long double** read_matrix_from_file(std::string file_name, const int &size) override;
    };
}
