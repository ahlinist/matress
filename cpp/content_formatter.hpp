#pragma once

#include <string>

#include "matrix.hpp"

namespace text {
    class ContentFormatter {
    public:
        virtual ~ContentFormatter() {}
        virtual std::string format_matrix(const matrix::Matrix &matrix) = 0;
    };

    class ContentFormatterImpl : public ContentFormatter {
    public:
        std::string format_matrix(const matrix::Matrix &matrix) override;
    };
}