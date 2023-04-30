#pragma once
#include <chrono>
#include <random>
#include <string>
#include <vector>

class Randomize : public std::mt19937_64 {
  public:
    Randomize(unsigned long long seed =
                  std::chrono::steady_clock::now().time_since_epoch().count());

    auto rand(unsigned long long l, unsigned long long r) -> unsigned long long;
    auto randListData() -> std::vector<std::string>;
};