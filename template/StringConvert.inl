#include <sstream>
template <typename T>
std::string toString(const T &value){
    std::stringstream ss;
    ss << value;
    return ss.str();
}

template <typename T>
int toNum(const T &value){
    int res;
    std::stringstream ss;
    ss << value;
    ss >> res;
    return res;
}