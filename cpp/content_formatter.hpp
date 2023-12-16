#pragma once

#include <string>

namespace text {
    class ContentFormatter {
    public:
        virtual ~ContentFormatter() {}
        virtual std::string format_matrix(long double** matrix, const int &size) = 0;
    };

    class ContentFormatterImpl : public ContentFormatter {
    public:
        std::string format_matrix(long double** matrix, const int &size) override;
    };
}