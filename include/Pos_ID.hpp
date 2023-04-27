#pragma once
#include "Constants.hpp"

#include <SFML/Graphics.hpp>

class Pos_ID{

    public:
        Pos_ID();

        bool init(int n);        
        bool attachID(int id);
        bool detachID(int id);

        int takeID(int pos);
        int findID(int id);

    private:
        int size_n;
        int ID[Constants::MAXI::numOfNode];
};