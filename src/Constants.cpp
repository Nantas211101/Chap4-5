#include "Constants.hpp"
#include "StringConvert.hpp"

bool isContain(int n, int l, int r) {
    if (l <= n && n <= r)
        return true;
    return false;
}

bool isContain(std::string s, int l, int r) {
    int n = toNum(s);
    if (l <= n && n <= r)
        return true;
    return false;
}