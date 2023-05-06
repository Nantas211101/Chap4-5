#pragma once
#include "Constants.hpp"
#include <string>
#include <vector>

std::vector<std::string> readIntegerFile(int numOfNullNode, const std::string& file_name,
                                 size_t max_n = Constants::MAXI::numOfNode,
                                 int min_val = Constants::MINI::valueOfNode,
                                 int max_val = Constants::MAXI::valueOfNode);