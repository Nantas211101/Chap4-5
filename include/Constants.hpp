#pragma once
#include <string>

struct Constants {
    const char acceptedChar[11] = {' ', '0', '1', '2', '3', '4',
                                   '5', '6', '7', '8', '9'};
    const int numOfAcceptedChar = 11;

    struct MAXI {
        static constexpr int numOfNode = 7;
        static constexpr int valueOfNode = 100;
    };

    struct MINI {
        static constexpr int numOfNode = 0;
        static constexpr int valueOfNode = 0;
    };

    std::string infoError1 = "Only integer are accepted, number of node should in [0, 7]";
    std::string infoError2 = "Value of node should in [0, 100]";
};
