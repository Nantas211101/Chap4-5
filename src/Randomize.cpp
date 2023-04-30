#include "Randomize.hpp"
#include "Constants.hpp"

Randomize::Randomize(unsigned long long seed) : std::mt19937_64(seed) {}

auto Randomize::rand(unsigned long long l, unsigned long long r)
    -> unsigned long long {
    return std::uniform_int_distribution<>(l, r)(*this);
}

auto Randomize::randListData() -> std::vector<std::string> {
    int n = this->rand(Constants::MINI::numOfNode, Constants::MAXI::numOfNode);
    std::vector<std::string> res;
    res.reserve(n);
    for (int i = 0; i < n; ++i) {
        int value = this->rand(Constants::MINI::valueOfNode,
                               Constants::MAXI::valueOfNode);
        res.push_back(std::to_string(value));
    }
    return  res;
}
