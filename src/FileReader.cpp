#include "FileReader.hpp"

#include <fstream>
#include <limits>

std::vector<int> readIntegerFile(const std::string& file_name, size_t max_n,
                                 int min_val, int max_val) {
    std::ifstream file(file_name);

    size_t n;
    file >> n;
    if (file.fail())
        throw std::runtime_error{"cannot read an integer"};
    if (n > max_n)
        throw std::runtime_error{"data too big"};

    std::vector<int> res;
    res.reserve(n);
    for (size_t i = 0; i < n; ++i) {
        int val;
        file >> val;
        if (file.fail())
            throw std::runtime_error{"cannot read an integer"};
        if (val < min_val || val > max_val)
            throw std::runtime_error{"value should be in range " +
                                     std::to_string(min_val) + " to " +
                                     std::to_string(max_val)};
        res.push_back(val);
    }
    file >> std::ws; // ignoring the whitespace
    if (!file.eof())
        throw std::runtime_error{"More data than needed"};

    return res;
}