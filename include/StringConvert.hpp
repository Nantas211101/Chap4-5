#pragma once
#include <sstream>

template <typename T>
std::string toString(const T &value);

template <typename T>
int toNum(const T &value);

#include "../template/StringConvert.inl"