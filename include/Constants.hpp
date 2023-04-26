#pragma once
#include <string>

struct Constants {
    const char acceptedChar[11] = {' ', '0', '1', '2', '3', '4',
                                   '5', '6', '7', '8', '9'};
    const int numOfAcceptedChar = 11;

    // enum MAXI {
    //     numOfNode = 7,
    //     valueOfNode = 100,
    // };

    // enum MINI {
    //     numOfNode = 0,
    //     valueOfNode = 0,
    // };

    std::string infoError1 = "Only integer are accepted, number of node should in [0, 7]";
    std::string infoError2 = "Value of node should in [0, 100]";
};
