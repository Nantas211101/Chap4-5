#pragma once
#include "Constants.hpp"

#include <SFML/Graphics.hpp>

class Pos_ID{

    public:
        Pos_ID();

        bool init(int n);  
        void reset();      
        bool attachID(int id);
        auto detachID(int id) -> int;

        int takeID(int pos);
        int findID(int id);

    private:
        int size_n;
        int ID[Constants::MAXI::numOfNode];
};